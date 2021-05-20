/*
** EPITECH PROJECT, 2021
** create a client
** File description:
** socket_client
*/

#include "sockets.h"

int client_create(int port, char *host)
{
    int client_fd = 0;

    if ((client_fd = socket_create()) == -1)
        return -1;
    if (socket_connect(client_fd, port, host) == -1)
        return -1;
    return client_fd;
}