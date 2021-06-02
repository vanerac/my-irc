/*
** EPITECH PROJECT, 2021
** C
** File description:
** server.c file
*/

#include <dlfcn.h>
#include "logging_server.h"
#include <sys/socket.h>
#include <sys/select.h>
#include "commands.h"
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

int get_max_fd(list_t *sessions, int server_socket)
{
    int max_fd = server_socket;
    list_t *tmp = sessions;

    while (tmp) {
        if (((session_t *) tmp->data)->socket > max_fd) {
            max_fd = ((session_t *) tmp->data)->socket;
        }
        tmp = tmp->next;
    }
    return max_fd;
}

int listen_updates(int server_socket, list_t *sessions, t_global *global,
    fd_set *rfds
)
{
    list_t *n = NULL;
    int status = 0;
    int max_fd = get_max_fd(sessions, server_socket);

    set_ports(rfds, sessions);
    FD_SET(server_socket, rfds);
    if (select(max_fd + 1, rfds, NULL, NULL, NULL) == -1)
        return 84;
    for (int i = 0; i < max_fd + 1 && status == 0; ++i)
        if (FD_ISSET(i, rfds) && i != server_socket) {
            n = node_find_fn(sessions, &find_session_by_fd, &i);
            status = handle_command(global, n ? n->data : NULL);
        } else if (FD_ISSET(i, rfds) && i == server_socket)
            handle_connections(sessions, server_socket);
    return status;
}

int myteams_server(int server_socket)
{
    fd_set rfds;
    FD_ZERO(&rfds);
    session_t *server_session = malloc(sizeof(session_t));
    if (!server_session)
        return 84;
    server_session->socket = server_socket;
    server_session->user_data = NULL;
    list_t *sessions = node_list_create(server_session);
    t_global global = {.all_user = NULL, .private_message = NULL, .teams =
    NULL, .sessions = sessions};
    if (!sessions)
        return 84;
    if (server_socket < 0)
        return 84;
    int status = 0;
    while (status != FATAL_ERROR)
        status = listen_updates(server_socket, sessions, &global, &rfds);
    return status;
}