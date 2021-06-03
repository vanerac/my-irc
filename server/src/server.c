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
#include "commands.h"
#include "struct.h"
#include "sockets.h"
#include "handles.h"
#include "list.h"

void set_ports(fd_set *rfds, list_t *sessions)
{
    FD_ZERO(rfds);
    for (list_t *i = sessions; i; i = i->next) {
        if (((session_t *) i->data)->connected)
            FD_SET(((session_t *) i->data)->socket, rfds);
    }
    FD_SET(0, rfds);
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

int read_stdin()
{
    char buffer[5] = {0};
    return !read(0, buffer, 5);
    return 0;
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

    for (int i = 0; i < max_fd + 1 && status == 0; ++i) {
        if (!FD_ISSET(i, rfds))
            continue;
        if (i == 0) {
            status = read_stdin();
        } else if (i == server_socket)
            handle_connections(sessions, server_socket);
        else {
            n = node_find_fn(sessions, &find_session_by_fd, &i);
            if (handle_command(global, n ? n->data : NULL) == HANGUP) {
                printf("%s\n", "client left");
                // todo remove session, its cleaner
                ((session_t *) n->data)->connected = false;
            }
        }
    }

    return status;
}

// todo handle sig

void load(t_global *global)
{
    (void) global;
    //    int fd = 0;
    //    global->teams = read_all_teams(fd, 4);
    //    global->all_user = read_all_users(fd, 4);
    //    data->private_message = read_all_messages(fd, 1);
    return;
}

void save(t_global *data, bool write)
{

    static t_global *data_save = NULL;
    if (!write) {
        data_save = data;
        return;
    }

    (void) data_save;
    // save teams
    //    int fd = 1; // todo

    // save all users on one file

    // save dms


}

void sig_save(int blc)
{
    (void) blc;
    printf("%s\n", "program killed by sig");
    save(NULL, true);
    exit(0);
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
    // todo load global
    save(&global, false); // save ptr;
    signal(SIGTERM, sig_save);
    signal(SIGINT, sig_save);
    //    signal(SIGSEGV, sig_save);
    if (!sessions)
        return 84;
    if (server_socket < 0)
        return 84;
    int status = 0;
    while (status == 0)
        status = listen_updates(server_socket, sessions, &global, &rfds);
    // todo // save global
    save(&global, true);
    return status == 84 ? 84 : 0;
}