/*
** EPITECH PROJECT, 2021
** C
** File description:
** file_tools.c file
*/

#include <string.h>
#include <unistd.h>
#include <server.h>
#include "file_parser.h"

static char *strcatdup(char *dest, char *src)
{
    size_t len1 = dest ? strlen(dest) : 0;
    size_t len2 = strlen(src);
    char *ret = malloc(sizeof(char) * len1 + len2 + 1);
    if (dest)
        memccpy(ret, dest, sizeof(char), len1);
    memccpy(!len1 ? ret : &ret[len1], src, sizeof(char), len2);
    ret[len1 + len2] = '\0';
    free(dest);
    return ret;
}

static char *get_line(int fd)
{
    char *ret = NULL, *buffer = NULL;
    bool quoted = false;

    for (buffer = malloc(2); read(fd, buffer, 1);) {
        buffer[1] = '\0';
        ret = strcatdup(ret, buffer);
        if (*buffer == '\"')
            quoted = !quoted;
        else if (*buffer == '\n' && !quoted)
            break;
    }
    free(buffer);
    return ret;
}

char **get_args(int fd, bool read)
{
    static char **prev_args = NULL;
    if (!read)
        return prev_args;
    char *buffer = get_line(fd);
    if (!buffer)
        return NULL;
    prev_args = split_by_quote(buffer);
    free(buffer);
    return prev_args;
}

