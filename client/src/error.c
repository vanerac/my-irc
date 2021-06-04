/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** error
*/

#include "client.h"

int check_args(int ac, char **ag)
{
    if (ac != 3) {
        fprintf(stderr, "%s\n%s\n", "USAGE: ./myteams_server port\n",
            "\tport is the port number on which the server socket listens.");
        return 84;
    }
    for (size_t i = 0; i < strlen(ag[2]); i++) {
        if (!isdigit(ag[2][i])) {
            fprintf(stderr, "Invalid port\n");
            return 84;
        }
    }
    return 0;
}