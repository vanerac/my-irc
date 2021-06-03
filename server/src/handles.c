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
    new_command.args = str_to_word_array(buffer, ' ');
    return new_command;
}

// int reply_to_client(session_t *session, enum command_e command,
    // enum command_return status)
// {
    // char *buffer = NULL;
    // asprintf(&buffer, "%d ERROR\n", status);
    // if (status < 0)
        // send_message(session->socket, buffer, RESPONSE, command);
    // return status;
// }

int handle_command(t_global *global, session_t *session)
{
    message_info_t info;

    if (!session)
        return SYSTEM_ERROR;
    if (!read_message(&info, session->socket))
        return SYSTEM_ERROR;
    command_t cmd = parse_command(info.args, info.command);
    enum command_return status = SUCCESS;
    for (command_ptr *fn = cmd.check_fn; status == SUCCESS && *fn; ++fn)
        status = (*fn)(global, session, cmd.args);

//        cmd.check_fn ? cmd.check_fn(global, session, cmd.args) : SUCCESS;
    if (status == SUCCESS)
        status = cmd.fn(global, session, cmd.args);
    return 0;
    // return reply_to_client(session, cmd.command_id, status);
}

void handle_connections(list_t *sessions, int server_socket)
{
    int client = socket_accept(server_socket);
    if (client < 0)
        return;
    session_t *data = malloc(sizeof(session_t));
    if (!data)
        return;
    data->socket = client;
    data->logged = false;
    data->user_data = NULL;
    data->current_team = NULL;
    data->current_channel = NULL;
    data->current_thread = NULL;
    node_append_data(sessions, data);
    send_message(client, "220 Welcome", RESPONSE, INVALID);
}