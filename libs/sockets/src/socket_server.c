/*
** EPITECH PROJECT, 2021
** create a server
** File description:
** socket_server
*/

#include "sockets.h"

int server_create(int port)
{
    int server_fd = 0;

    if ((server_fd = socket_create()) == -1)
        return -1;
    if (socket_bind(server_fd, port) == -1)
        return -1;
    if (socket_listen(server_fd) == -1)
        return -1;
    return server_fd;
}