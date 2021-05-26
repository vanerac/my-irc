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

command_t parse_command(char *buffer)
{
    (void) buffer;
    return commands_list[INVALID];
}


int handle_command(session_t *session)
{
    if (!session)
        return SYSTEM_ERROR;
    char *buffer = socket_read(session->socket);
    if (!buffer)
        return SYSTEM_ERROR;
    command_t cmd = parse_command(buffer);
    return cmd.fn(session, cmd.args);
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
}