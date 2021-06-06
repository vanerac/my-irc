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
    ret->replies = NULL;
    ret->m_type = M_DM;
    return ret;
}

void command_send(t_global *global, session_t *session, char **args)
{
    uuid target, *uuids[2] = {&session->user_data->uid, &target};
    uuid_parse(args[0], target);
    char tmp[37];
    CHECK_ARGS(args, 2, session->socket)
    if (!node_find_fn(global->all_user, &find_by_uuid, args[0])) {
        SEND_MESSAGE(session->socket, RESPONSE, SEND, "401 \"%s\"\n", args[0]);
        return;
    }
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);
    t_dm *dm = dms ? dms->data : create_dm(global, session, target);
    t_messages *ret = init_message(session->user_data, dm, args[1]);
    NODE_ADD(dm->messages, ret)
    list_t *target_session = node_find_fn(global->sessions, &find_by_uuid,
        target);
    uuid_unparse(session->user_data->uid, tmp);
    if (target_session &&
        ((session_t *) target_session->data)->logged) SEND_MESSAGE(
        ((session_t *) target_session->data)->socket, RESPONSE, SEND,
        "200 \"%s\" \"%s\"", tmp, ret->body)
    server_event_private_message_sended(tmp, args[0], args[1]);
}