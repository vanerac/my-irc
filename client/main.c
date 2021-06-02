/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <string.h>
#include "sockets.h"
#include "client.h"

int main(int ac, char **ag)
{
    struct data *var = malloc(sizeof(struct data));

    if (ac < 3 || !var)
        return 84;

    var->server_fd = client_create(atoi(ag[2]), ag[1]);
    var->buffer_client = calloc(sizeof(char), 200);
    var->buffer_server = calloc(sizeof(char), 200);

    message_info_t ok;

    while (1) {
        if (read_message(&ok, var->server_fd))
            server_handler(&ok);

        if (read(0, var->buffer_client, 200) != 0)
            send_message(var->server_fd, var->buffer_client, COMMAND, INVALID);
    }
    dlclose(var->handle);
}