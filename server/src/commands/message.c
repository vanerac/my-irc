/*
** EPITECH PROJECT, 2021
** messsages
** File description:
** message
*/

#include "commands.h"
#include "message.h"

void messages_second_part(session_t *session, char **args,
    uuid target, list_t *dms)
{
    char *buff = NULL;
    t_dm *dm = NULL;
    t_messages *m = NULL;
    char id[37];

    uuid_parse(args[0], target);
    dm = dms->data;
    for (list_t *i = dm->messages; i; i = i->next) {
        m = i->data;
        uuid_unparse(m->author_uuid, id);
        asprintf(&buff, "200 \"%s\" \"%ld\" \"%s\"\n", id,
            m->created_at, m->body);
        send_message(session->socket, buff, RESPONSE, MESSAGES);
        free(buff);
    }
}

void command_messages(t_global *global, session_t *session, char **args)
{
    uuid target;
    uuid_parse(args[0], target);
    uuid *uuids[2] = {&session->user_data->uid, &target};
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);
    char *buff = NULL;

    CHECK_ARGS(args, 1, session->socket)
    if (!dms) {
        asprintf(&buff, "401 \"%s\"", args[0]);
        send_message(session->socket, buff, RESPONSE, MESSAGES);
        free(buff);
        return;
    }
    messages_second_part(session, args, target, dms);
}