/*
** EPITECH PROJECT, 2021
** C
** File description:
** file_tools.c file
*/

#include <string.h>
#include <unistd.h>
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

static char *clean_str(char *buffer)
{
    // todo
    return buffer;
}

static list_t *parse_args(char *line)
{
    list_t *args = NULL;
    char *buffer = line;
    bool quoted = false;

    for (size_t i = 0; buffer[i]; ++i) {
        if (buffer[i] == '\"')
            quoted = !quoted;
        else if (buffer[i] != ' ' || quoted)
            continue;
        while (buffer[i] == ' ')
            ++i;
        if (!args)
            args = node_list_create(clean_str(strndup(buffer, i)));
        else
            node_append_data(args, clean_str(strndup(buffer, i)));

        buffer += i - 1, i = -1;
    }
    return args;
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

    list_t *args = parse_args(buffer);
    size_t i = 0, size = 0;
    for (list_t *ptr = args; ptr; size++, ptr = ptr->next);
    prev_args = malloc(sizeof(char *) * size + 1);
    if (!prev_args)
        return NULL;
    for (list_t *prev, *ptr = args; ptr; prev = ptr, ptr = ptr->next, free(
        prev), ++i)
        prev_args[i] = ptr->data;
    prev_args[size] = NULL;
    free(buffer);
    return prev_args;
}

