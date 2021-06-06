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
    char **args)
{
    if (!session->current_team) {
        return create_team(global, session, args[0], args[1]);
    }
    if (!session->current_channel) {
        return create_channel(session->current_team, session, args[0],
            args[1]);
    }
    if (!session->current_thread) {
        return create_tread(session->current_channel, session, args[0],
            args[1]);
    } else {
        return create_comment(session->current_thread, session, args[0]);
    }
    return SUCCESS;
}

enum command_return check_nb_arg(session_t *session, char **args)
{
    if (!session->current_team) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
    }
    if (!session->current_channel) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
    }
    if (!session->current_thread) {
        if (!args || !args[0] || !args[1])
            return INVALID_ARGS;
    } else {
        if (!args || !args[0])
            return INVALID_ARGS;
    }
    return SUCCESS;
}

enum command_return check_size_args(session_t *session, char **args)
{
    if (!session->current_team) {
        if (strlen(args[0]) > 32 || strlen(args[1]) > 255)
            return TOO_LONG_ARGS;
    }
    if (!session->current_channel) {
        if (strlen(args[0]) > 32 || strlen(args[1]) > 255)
            return TOO_LONG_ARGS;
    } else {
        if (strlen(args[0]) > 512)
            return TOO_LONG_ARGS;
    }
    return SUCCESS;   
}

void command_create(t_global *global, session_t *session, char **args)
{
    (void) args;
    enum command_return return_val = SUCCESS;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    if ((return_val = check_nb_arg(session, args))== INVALID_ARGS) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    if ((return_val = check_size_args(session, args)) == TOO_LONG_ARGS) {
        send_message(session->socket, "665 too long args", RESPONSE, INVALID);
        return;
    }
    if ((return_val = call_create(global, session, args)) == SYSTEM_ERROR) {
        send_message(session->socket, "666 system error", RESPONSE, INVALID);
    }
}