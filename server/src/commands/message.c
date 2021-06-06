/*
** EPITECH PROJECT, 2021
** messsages
** File description:
** message
*/

#include "commands.h"
#include "message.h"

void messages_second_part()
{
    
}

void command_messages(t_global *global, session_t *session, char **args)
{
    uuid target;
    uuid *uuids[2] = {&session->user_data->uid, &target};
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);
    t_dm *dm = NULL;
    t_messages *m = NULL;
    char *buff = NULL;
    char id[37];

    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    if (!dms) {
        asprintf(&buff, "401 \"%s\"", args[0]);
        send_message(session->socket, buff, RESPONSE, MESSAGES);
        free(buff);
        return;
    }
    uuid_parse(args[0], target);
    dm = dms->data;
    for (list_t *i = dm->messages; i; i = i->next) {
        m = i->data;
        uuid_unparse(m->author->uid, id);
        asprintf(&buff, "200 \"%s\" \"%ld\" \"%s\"\n", id,
            m->created_at, m->body);
        send_message(session->socket, buff, RESPONSE, MESSAGES);
        free(buff);
    }
}