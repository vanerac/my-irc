/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include "sockets.h"
#include "client.h"

int main(int ac, char **ag)
{
    struct data *var = malloc(sizeof(var));
    var->login = malloc(sizeof(char *));
    var->login = UNSET;

    if (ac < 2)
        return 84;

    var->server_fd = client_create(atoi(ag[1]), "127.0.0.1");
    var->buffer_client = calloc(sizeof(char), 200);
    var->buffer_server = calloc(sizeof(char), 200);

    while (var->buffer_client) {
        read(var->server_fd, var->buffer_server, 200);
        // printf("buffer server => %s\n", var->buffer_server);
        memset(var->buffer_server, 0, 200);

        read(0, var->buffer_client, 200);
        client_command_handler(var);
        // printf("buffer client => %s\n", var->buffer_client);
        write(var->server_fd, var->buffer_client, strlen(var->buffer_client));
        memset(var->buffer_client, 0, 200);
    }
}