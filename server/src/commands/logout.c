/*
** EPITECH PROJECT, 2021
** C
** File description:
** logout.c file
*/

#include <logging_server.h>
#include <string.h>
#include "commands.h"
#include "message.h"

void command_logout(t_global *global, session_t *session, char **args
)
{
    (void) global, (void) args;
    char uuid[37];
    uuid_unparse(session->user_data->uid, uuid);
    server_event_user_logged_out(uuid);

    SEND_MESSAGE(session->socket, RESPONSE, LOGOUT, "200 \"%s\" \"%s\"", uuid,
        ((t_user *) session->user_data)->username)
    session->logged = false;
    session->user_data->logged = false;
    session->user_data = NULL;
}