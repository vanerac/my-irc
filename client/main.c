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
        if (read_message(&ok, var->server_fd)){
            printf("buffer server => %s\n", ok.args);
            server_handler(&ok);
            // memset(ok.args, 0, 200);
            printf("SERVER\n");
        }

        if (read(0, var->buffer_client, 200) != 0){
            printf("buffer client => %s\n", var->buffer_client);
            send_message(var->server_fd, var->buffer_client, COMMAND, INVALID);
            // memset(var->buffer_client, 0, 200);
            printf("CLIENT\n");
        }
    }
    dlclose(var->handle);
}