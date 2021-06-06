/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** handles.c file
*/

#include <stdio.h>
#include "commands.h"
#include "struct.h"
#include "sockets.h"
#include "list.h"
#include "server.h"
#include "message.h"

int asprintf(char **strp, const char *fmt, ...);

command_t parse_command(char *buffer, enum command_e command)
{
    command_t new_command = commands_list[command];
    new_command.args = split_by_quote(buffer);
    return new_command;
}

int handle_command(t_global *global, session_t *session)
{
    message_info_t info;

    if (!session)
        return SYSTEM_ERROR;
    if (!read_message(&info, session->socket))
        return HANGUP;
    command_t cmd = parse_command(info.args, info.command);
    if (!cmd.args)
        return SYSTEM_ERROR;
    enum command_return status = SUCCESS;
    for (command_ptr *fn = cmd.check_fn; status == SUCCESS && *fn; ++fn)
        status = (*fn)(global, session, cmd.args);
    if (status == SUCCESS)
        cmd.fn(global, session, cmd.args);
    return 0;
}

void handle_connections(list_t *sessions, int server_socket)
{
    int client = socket_accept(server_socket);
    if (client < 0)
        return;
    session_t *data = malloc(sizeof(session_t));
    if (!data)
        return;
    data->type = SESSION;
    data->socket = client;
    data->logged = false;
    data->user_data = NULL;
    data->current_team = NULL;
    data->current_channel = NULL;
    data->current_thread = NULL;
    NODE_ADD(sessions, data)
    send_message(client, "220 Welcome", RESPONSE, INVALID);
}