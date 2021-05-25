/*
** EPITECH PROJECT, 2021
** C
** File description:
** io_functions.c file
*/

#include "sockets.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *strcatndup(char *dest, char *src, size_t size)
{
    size_t len = strlen(dest) + size;
    char *ret = malloc((sizeof(char) * len) + 1);
    if (!ret)
        return NULL;

    memcpy(ret, dest, sizeof(char) * strlen(dest));
    memcpy(&ret[strlen(dest)], src, sizeof(char) * size);
    ret[len] = '\0';
    free(dest);
    return ret;
}

char *socket_read(int fd)
{
    char *ret = NULL;
    char *buffer = malloc(sizeof(char) * RD_SIZE);
    if (!buffer)
        return NULL;
    size_t rd = 0;
    for (; (rd = read(fd, buffer, RD_SIZE)) == RD_SIZE; memset(buffer, 0,
        RD_SIZE))
        ret = strcatndup(ret, buffer, rd);

    if (strlen(buffer))
        ret = strcatndup(ret, buffer, rd);
    char *decoded = binary_decode(ret);
    free(ret);
    return ret;
}

size_t socket_write(int socket, char *buffer)
{
    char *snd = binary_encode(buffer);

    size_t ret = write(socket, snd, strlen(snd));
    free(snd);
    return ret;
}