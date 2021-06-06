/*
** EPITECH PROJECT, 2021
** messsages
** File description:
** message
*/

#include "commands.h"
#include "message.h"

void command_messages(t_global *global, session_t *session, char **args)
{
    uuid target;
    uuid *uuids[2] = {&session->user_data->uid, &target};
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);

    CHECK_ARGS(args, 1, session->socket)
    uuid_parse(args[0], target);
    if (!dms) {
        SEND_MESSAGE(session->socket, RESPONSE, MESSAGES, "401 \"%s\"",
            args[0]);
        return;
    }
    t_dm *dm = dms->data;
    for (list_t *i = dm->messages; i; i = i->next) {
        t_messages *m = i->data;
        char id[37];
        uuid_unparse(m->author->uid, id);
        SEND_MESSAGE(session->socket, RESPONSE, MESSAGES,
            "200 \"%s\" \"%lud\" \"%s\"\n", id, m->created_at, m->body)
    }
}