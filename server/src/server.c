/*
** EPITECH PROJECT, 2021
** C
** File description:
** server.c file
*/

#include "struct.h"
#include "sockets.h"
#include "handles.h"
#include "list.h"

void set_ports(fd_set *rfds, list_t *sessions)
{
    FD_ZERO(rfds);
    for (list_t *i = sessions; i; i = i->next) {
        FD_SET(((t_session *) i->data)->socket, rfds);
    }
}

int listen_updates(int server_socket, list_t *sessions, fd_set *rfds)
{
    set_ports(rfds, sessions);
    FD_SET(server_socket, rfds);
    if (select(FD_SETSIZE, rfds, NULL, NULL, NULL) == -1)
        return 84;
    for (int i = 0; i < FD_SETSIZE; ++i)
        if (FD_ISSET(i, rfds) && i != server_socket)
            handle_command(i);
        else if (FD_ISSET(i, rfds) && i == server_socket)
            handle_connections(sessions, server_socket);
    return 0;
}

int myteams_server(int server_socket)
{
    fd_set rfds;
    FD_ZERO(&rfds);
    //    int server_socket = server_create(port);

    int *data = malloc(sizeof(int));
    *data = server_socket;
    list_t *sessions = node_list_create(data);
    if (!sessions)
        return 84;

    if (server_socket < 0)
        return 84;

    int status = 0;
    while (status == 0)
        status = listen_updates(server_socket, sessions, &rfds);

    return 0;
}