/*
** EPITECH PROJECT, 2021
** user
** File description:
** user
*/

#include "commands.h"
#include "message.h"

void command_usr(t_global *global, session_t *session, char **args)
{
    char *buffer;
    char uuid[37];
    session_t *user = NULL;
    list_t *node = NULL;

    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    node = node_find_fn(global->sessions, find_by_uuid, args[0]);
    if (!node) {
        asprintf(&buffer, "401 \"%s\"", args[0]);
        send_message(session->socket, buffer, RESPONSE, USR);
        return;
    }
    user = (session_t *) node->data;
    uuid_unparse(((t_user *) user->user_data)->uid, uuid);
    asprintf(&buffer, "200 \"%s\" \"%s\" \"%i\"", uuid,
        ((t_user *) user->user_data)->username, user->logged ? 1 : 0);
    send_message(session->socket, buffer, RESPONSE, USR);
    free(buffer);
}