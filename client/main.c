/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <string.h>
#include "sockets.h"
#include "client.h"

void set_client_fd(fd_set *rfds, int client_fd)
{
    FD_ZERO(rfds);
    FD_SET(0, rfds);
    FD_SET(client_fd, rfds);
}

bool client_read(int i, int client_fd)
{
    message_info_t ok;
    char reading[1024] = {0};
    int total_read = 0;

    if (i == 0) {
        total_read = read(0, reading, 200);
        if (total_read == 0)
            return false;
        if (total_read > 0)
            send_message(client_fd, reading, COMMAND, INVALID);
    }
    if (i == client_fd) {
        if (read_message(&ok, client_fd))
            server_handler(&ok);
    }
    return true;
}

bool client_read_by_fd(int client_fd, fd_set *rfds)
{
    for (int i = 0; i < client_fd + 1; i++) {
        if (FD_ISSET(i, rfds)) {
            return client_read(i, client_fd);
        }
    }
    return true;
}

int client(int client_fd)
{
    fd_set rfds;
    bool status = true;

    while (status) {
        set_client_fd(&rfds, client_fd);
        if (select(client_fd + 1, &rfds, NULL, NULL, NULL) == -1)
            return 84;
        status = client_read_by_fd(client_fd, &rfds);
    }
    return 0;
}

int main(int ac, char **ag)
{
    if (check_args(ac, ag))
        return (84);

    int server_fd = client_create(atoi(ag[2]), ag[1]);

    return client(server_fd);
}