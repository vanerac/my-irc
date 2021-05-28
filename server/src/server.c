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
        FD_SET(((session_t *) i->data)->socket, rfds);
    }
}

static bool find_session_by_fd(void *iterator, void *value)
{
    return ((session_t *) iterator)->socket == *(int *) value;
}

int listen_updates(int server_socket, list_t *sessions, t_global *global,
    fd_set *rfds
)
{
    set_ports(rfds, sessions);
    FD_SET(server_socket, rfds);
    if (select(FD_SETSIZE, rfds, NULL, NULL, NULL) == -1)
        return 84;
    int status = 0;
    for (int i = 0; i < FD_SETSIZE && status == 0; ++i)
        if (FD_ISSET(i, rfds) && i != server_socket) {
            list_t *n = node_find_fn(sessions, &find_session_by_fd, &i);
            status = handle_command(global, n ? n->data : NULL);
        } else if (FD_ISSET(i, rfds) && i == server_socket)
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
    t_global global = {.all_user = NULL, .private_message = NULL, .teams =
    NULL};
    if (!sessions)
        return 84;

    if (server_socket < 0)
        return 84;

    int status = 0;
    while (status == 0)
        status = listen_updates(server_socket, sessions, &global, &rfds);

    return 0;
}