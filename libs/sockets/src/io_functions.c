/*
** EPITECH PROJECT, 2021
** C
** File description:
** io_functions.c file
*/

#include "sockets.h"

//static char *strcatndup(char *dest, char *src, size_t size)
//{
//    size_t len = strlen(dest) + size;
//    char *ret = malloc(sizeof(char) * len + 1);
//    if (!ret)
//        return NULL;
//
//    memcpy(ret, dest, sizeof(char) * strlen(dest));
//    memcpy(&ret[strlen(dest) - 1], src, sizeof(char) * size);
//    ret[len] = '\0';
//    free(dest);
//    return ret;
//}

char *socket_read(int fd)
{
    (void) fd;
    return NULL;
//
//    char *ret = NULL;
//    char *buffer = malloc(sizeof(char) * RD_SIZE);
//    if (!buffer)
//        return NULL;
//
//    for (size_t rd = 0; (rd = read(fd, buffer, RD_SIZE)) == RD_SIZE;
//    memset(buffer, 0, RD_SIZE))
//    ret = strcatndup(ret, buffer, rd);
//
//    if (strlen(buffer))
//        ret = strcatndup(ret, buffer, rd);
//    char *decoded = binary_decode(ret);
//    free(ret);
//    return ret;
}

size_t socket_write(int socket, char *buffer)
{
    (void) socket, (void) buffer;
//    char *snd = binary_encode(buffer);
//    size_t ret = 0;
//    for (; write(socket, buffer, ))
    return 0;
}