/*
** EPITECH PROJECT, 2021
** C
** File description:
** send.c file
*/

#include <commands.h>
#include <message.h>
#include <logging_server.h>

int asprintf(char **restrict strp, const char *restrict fmt, ...);

bool find_dms(void *it, void *data)
{
    return (!uuid_compare(((t_dm *) it)->user_first, *((uuid **) data)[0]) ||
        !uuid_compare(((t_dm *) it)->user_first, *((uuid **) data)[1])) &&
        (!uuid_compare(((t_dm *) it)->user_second, *((uuid **) data)[0]) ||
            !uuid_compare(((t_dm *) it)->user_second, *((uuid **) data)[1]));
}

static t_dm *create_dm(t_global *global, session_t *session, uuid target)
{
    t_dm *ret = malloc(sizeof(t_dm));
    uuid_copy(ret->user_first, session->user_data->uid);
    uuid_copy(ret->user_second, target);
    ret->type = DM;
    ret->messages = NULL;
    NODE_ADD(global->private_message, ret)
    return ret;
}

static t_messages *init_message(t_user *author, void *destination, char *body)
{
    t_messages *ret = malloc(sizeof(t_messages));
    ret->type = MESSAGE;
    uuid_generate(ret->uid);
    ret->author = author;
    ret->destination = destination;
    ret->body = body;
    ret->title = NULL;
    time(&ret->created_at);
    uuid_copy(ret->author_uuid, author->uid);
    ret->replies = NULL;
    ret->m_type = M_DM;
    return ret;
}

void send_second_part(t_global *global, session_t *session, char **args,
    uuid *target)
{
    char *buff = NULL;
    char tmp[37];
    uuid *uuids[2] = {&session->user_data->uid, target};
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);
    t_dm *dm = dms ? dms->data : create_dm(global, session, *target);
    t_messages *ret = init_message(session->user_data, dm, args[1]);
    NODE_ADD(dm->messages, ret)
    uuid_unparse(*target, tmp);
    list_t *target_session = node_find_fn(global->sessions, &find_by_uuid,
        tmp);

    uuid_unparse(session->user_data->uid, tmp);
    if (target_session && ((session_t *) target_session->data)->logged) {
        asprintf(&buff, "200 \"%s\" \"%s\"", tmp, ret->body);
        send_message(((session_t *) target_session->data)->socket, buff,
            RESPONSE, SEND);
        free(buff);
    }
    server_event_private_message_sended(tmp, args[0], args[1]);
}

void command_send(t_global *global, session_t *session, char **args)
{
    uuid target;
    char *buff = NULL;

    if (!args || !args[0] || !args[1]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    if (strlen(args[1]) > 512) {
        send_message(session->socket, "665 too long args", RESPONSE, INVALID);
        return;
    }
    uuid_parse(args[0], target);
    if (!node_find_fn(global->all_user, &find_by_uuid, args[0])) {
        asprintf(&buff, "401 \"%s\"\n", args[0]);
        send_message(session->socket, buff, RESPONSE, SEND);
        free(buff);
        return;
    }
    send_second_part(global, session, args, &target);
}