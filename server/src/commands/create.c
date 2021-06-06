/*
** EPITECH PROJECT, 2021
** C
** File description:
** create.c file
*/

#include <string.h>
#include "logging_server.h"
#include "server.h"
#include "commands.h"
#include "message.h"

enum command_return call_create(t_global *global, session_t *session,
    char **args
)
{
    if (!session->current_team) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
        return create_team(global, session, args[0], args[1]);
    }
    if (!session->current_channel) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
        return create_channel(session->current_team, session, args[0],
            args[1]);
    }
    if (!session->current_thread) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
        return create_tread(session->current_channel, session, args[0],
            args[1]);
    } else {
        if (!args || !args[0])
            return INVALID_ARGS;
        return create_comment(session->current_thread, session, args[0]);
    }
}

void command_create(t_global *global, session_t *session, char **args
)
{
    (void) args;
    enum command_return return_val = SUCCESS;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    return_val = call_create(global, session, args);
    if (return_val == SYSTEM_ERROR) {
        send_message(session->socket, "666 system error", RESPONSE, INVALID);
    }
    if (return_val == INVALID_ARGS)
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
}