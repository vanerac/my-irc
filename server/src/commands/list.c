/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

enum command_return call_list(t_global *global, session_t *session)
{
    if (session->current_thread)
        return dump_messages(global, session);
    if (session->current_channel)
        return dump_threads(global, session);
    if (session->current_team)
        return dump_channels(global, session);
    else
        return dump_teams(global, session);
}

void command_list(t_global *global, session_t *session, char **args)
{
    (void) args;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    call_list(global, session);
}