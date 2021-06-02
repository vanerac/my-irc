/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <string.h>
#include "sockets.h"
#include "client.h"

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void set_client_fd(fd_set *rfds, int client_fd)
{
    FD_ZERO(rfds);
    FD_SET(0, rfds);
    FD_SET(client_fd, rfds);
}

int client(int client_fd)
{
    fd_set rfds;
    message_info_t ok;
    char reading[1024] = {0};

    while (1) {
        set_client_fd(&rfds, client_fd);
        if (select(client_fd + 1, &rfds, NULL, NULL, NULL) == -1) {
            return 84;
        }
        for (int i = 0; i < client_fd + 1; i++) {
            if (FD_ISSET(i, &rfds)) {
                if (i == 0) {
                    if (read(0, reading, 200) != 0)
                        send_message(client_fd, reading, COMMAND, INVALID);
                }
                if (i == client_fd) {
                    if (read_message(&ok, client_fd))
                        server_handler(&ok);
                }
            }
        }
    }
}


int main(int ac, char **ag)
{
    // struct data *var = malloc(sizeof(struct data));

    if (ac < 3)
        return 84;

    int server_fd = client_create(atoi(ag[2]), ag[1]);
    // var->buffer_client = calloc(sizeof(char), 200);
    // var->buffer_server = calloc(sizeof(char), 200);

    client(server_fd);
}