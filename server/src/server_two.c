/*
** EPITECH PROJECT, 2021
** server
** File description:
** server_two
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

void set_ports(fd_set *rfds, list_t *sessions, int server_socket)
{
    FD_ZERO(rfds);
    FD_SET(server_socket, rfds);
    for (list_t *i = sessions; i; i = i->next)
        FD_SET(((session_t *) i->data)->socket, rfds);
    FD_SET(0, rfds);
}

bool find_session_by_fd(void *iterator, void *value)
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

int read_stdin(void)
{
    char buffer[5] = {0};
    return !read(0, buffer, 5);
}