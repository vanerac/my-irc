/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** handles.c file
*/

#include "sockets.h"
#include "list.h"
#include "../../includes/sockets.h"
#include "../../includes/list.h"
#include "../../libs/sockets/includes/sockets.h"

int handle_command(int socket)
{
    (void) socket;
    return 0;
}

void handle_connections(list_t *sessions, int server_socket)
{
    int client = socket_accept(server_socket);
    if (client < 0)
        return;
    int *data = malloc(sizeof(int));
    if (!data)
        return;
    *data = client;
    node_append_data(sessions, data);
}