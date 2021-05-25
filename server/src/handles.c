/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** handles.c file
*/

#include <stdio.h>
#include "struct.h"
#include "sockets.h"
#include "list.h"

int handle_command(int socket)
{
    (void) socket;
    // todo find session
    // todo read
    // todo parse command
    return 0;
}

void handle_connections(list_t *sessions, int server_socket)
{
    int client = socket_accept(server_socket);
    if (client < 0)
        return;
    t_session *data = malloc(sizeof(t_session));
    if (!data)
        return;
    data->socket = client;
    data->logged = false;
    data->user_data = NULL;
    node_append_data(sessions, data);
}