/*
** EPITECH PROJECT, 2021
** C
** File description:
** binary_encoder.c file
*/

#include "sockets.h"
#include <string.h>
#include <stdlib.h>

static char *strcatndup(char *dest, char *src, size_t size)
{
    size_t len = strlen(dest) + size;
    char *ret = malloc((sizeof(char) * len) + 1);
    if (!ret)
        return NULL;

    memcpy(ret, dest, sizeof(char) * strlen(dest));
    memcpy(&ret[strlen(dest)], src,
        sizeof(char) * size);
    ret[len] = '\0';
    free(dest);
    return ret;
}

static int my_pow(size_t nb, size_t p)
{
    int res = nb;

    if (p == 0)
        return (1);

    res *= my_pow(nb, p - 1);
    return res;
}

char *binary_encode(const char *buffer)
{
    char *ret = calloc(sizeof(char), 10);
    if (!ret)
        return NULL;

    for (size_t i = 0; buffer[i]; ++i) {
        char b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        unsigned char t = buffer[i];
        for (int k = 7; k >= 0; --k, t >>= 1)
            b[k] = (t & 1) + '0';
        ret = strcatndup(ret, b, 8);
    }
    return ret;
}

char *binary_decode(const char *buffer)
{
    size_t len = strlen(buffer);
    char *ret = calloc(sizeof(char), len / 8);
    if (!ret)
        return NULL;
    if (len % 8)
        return NULL;

    for (size_t i = 0; i < len / 8; ++i) {
        for (int k = 7; k >= 0; --k)
            ret[i] += (((buffer[i * 8 + k]) - '0') * my_pow(2, 7 - k));
    }
    return ret;
}