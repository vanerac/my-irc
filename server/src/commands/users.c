/*
** EPITECH PROJECT, 2021
** users
** File description:
** users
*/

#include "logging_server.h"
#include "commands.h"
#include "message.h"

void command_users(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    list_t *all_users = global->all_user;
    t_user *cur = NULL;
    char uuid[37];

    for (; all_users; all_users = all_users->next) {
        cur = (t_user *) all_users->data;
        if (!cur)
            continue;
        uuid_unparse(cur->uid, uuid);
        SEND_MESSAGE(session->socket, RESPONSE, USERS,
            "200 \"%s\" \"%s\" \"%d\"\n", uuid, cur->username,
            (cur->logged) ? 1 : 0)
    }
}