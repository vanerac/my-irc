/*
** EPITECH PROJECT, 2021
** C
** File description:
** selective_read.c file
*/

#include "file_parser.h"

list_t *read_all_teams(int fd, int recursion_level)
{
    list_t *ret = NULL;
    for (void *data; (data = file_read_team(fd, recursion_level));)
        if (!ret)
            ret = node_list_create(data);
        else
            node_append_data(ret, data);
    return ret;
}

list_t *read_all_channels(int fd, int recursion_level)
{
    (void) fd, (void) recursion_level;
    return NULL;
}

list_t *read_all_threads(int fd, int recursion_level)
{
    (void) fd, (void) recursion_level;
    return NULL;
}

list_t *read_all_messages(int fd, int recursion_level)
{
    (void) fd, (void) recursion_level;
    return NULL;
}

list_t *read_all_users(int fd)
{
    list_t *ret = NULL;
    for (void *data; (data = file_read_user(fd));)
        if (!ret)
            ret = node_list_create(data);
        else
            node_append_data(ret, data);
    return ret;
}

list_t *read_all_dm(int fd, int recursion_level)
{
    list_t *ret = NULL;
    for (void *data; (data = file_read_dm(fd, recursion_level));)
        if (!ret)
            ret = node_list_create(data);
        else
            node_append_data(ret, data);
    return ret;
}