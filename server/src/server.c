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
#include <unistd.h>
#include <file_parser.h>
#include <signal.h>
#include <fcntl.h>
#include "commands.h"
#include "struct.h"
#include "sockets.h"
#include "handles.h"
#include "list.h"

void listen_second(list_t *sessions, t_global *global, int *i)
{
    list_t *n = NULL;

    n = node_find_fn(sessions, &find_session_by_fd, i);
    if (n && handle_command(global, n->data) == HANGUP) {
        command_logout(global, n->data, NULL);
        node_delete_data(global->sessions, n->data);
    }
}

int listen_updates(int server_socket, list_t *sessions, t_global *global,
    fd_set *rfds)
{
    int status = 0;
    int max_fd = get_max_fd(sessions, server_socket);

    set_ports(rfds, sessions, server_socket);
    if (select(max_fd + 1, rfds, NULL, NULL, NULL) == -1)
        return 84;
    for (int i = 0; i < max_fd + 1 && status == 0; ++i) {
        if (!FD_ISSET(i, rfds))
            continue;
        if (i == 0) {
            status = read_stdin();
        } else if (i == server_socket)
            handle_connections(sessions, server_socket);
        else {
            listen_second(sessions, global, &i);
        }
    }
    return status;
}

int server_second(list_t *sessions, int server_socket, t_global global,
    fd_set rfds)
{
    int status = 0;

    if (!sessions)
        return 84;
    if (server_socket < 0)
        return 84;
    while (status == 0)
        status = listen_updates(server_socket, sessions, &global, &rfds);
    save(&global, true);
    return status == 84 ? 84 : 0;
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
    load(&global);
    save(&global, false);
    signal(SIGTERM, sig_save);
    signal(SIGINT, sig_save);
    return server_second(sessions, server_socket, global, rfds);
}