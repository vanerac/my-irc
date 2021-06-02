/*
** EPITECH PROJECT, 2021
** C
** File description:
** main.c file
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "sockets.h"
#include "server.h"

int check_args(int ac, char **ag)
{
    if (ac != 2) {
        fprintf(stderr, "%s\n%s\n", "USAGE: ./myteams_server port\n",
            "\tport is the port number on which the server socket listens.");
        return -1;
    }
    for (size_t i = 0; i < strlen(ag[1]); i++) {
        if (isdigit(ag[1][i]) == 0) {
            fprintf(stderr, "Invalid port\n");
            return -1;
        }
    }
    return 0;
}

int main(int ac, char **ag)
{
    int server_fd = 0;

    if (check_args(ac, ag) == -1)
        return 84;
    if ((server_fd = server_create(atoi(ag[1]))) == -1)
        return 84;
    printf("%i\n", server_fd);
    myteams_server(server_fd); // todo return code (84)
    return 0;
}