/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "sockets.h"

int main(int ac, char **ag)
{
    if (ac < 2)
        return 84;

    int fd = client_create(atoi(ag[1]), "127.0.0.1");
    char *buffer = calloc(sizeof(char), 200);

    while (buffer) {
        read(fd, buffer, 200);
        printf("buff server => %s\n", buffer);
        memset(buffer, 0, 200);
        read(0, buffer, 200);
        printf("my buffer => %s\n", buffer);
        write(fd, buffer, strlen(buffer));
    }
}