/*
** EPITECH PROJECT, 2021
** info command
** File description:
** info
*/

#include "commands.h"
#include "message.h"

enum command_return call_info(session_t *session)
{
    if (session->current_thread)
        return thread_info(session);
    if (session->current_channel)
        return channel_info(session);
    if (session->current_team)
        return team_info(session);
    else
        return user_info(session);
}

void command_info(t_global *global, session_t *session, char **args)
{
    (void) args;
    (void) global;
    enum command_return ret_val = SUCCESS;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    ret_val = call_info(session);
    if (ret_val != SYSTEM_ERROR)
        send_message(session->socket, "666 \"system error\"", RESPONSE, LIST);
}