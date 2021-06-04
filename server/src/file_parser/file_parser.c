/*
** EPITECH PROJECT, 2021
** C
** File description:
** file_parser.c file
*/

#include "file_parser.h"

void write_structure(int fd, void *data, int recursion_levels)
{
    switch (*((enum data_type *) data)) {
    case UNKNOWN:
        return;
    case USER:
        return write_user(fd, data);
    case TEAM:
        return write_team(fd, data, recursion_levels);
    case CHANNEL:
        return write_channel(fd, data, recursion_levels);
    case THREAD:
        return write_thread(fd, data, recursion_levels);
    case REPLY:
        return write_message(fd, data);
    case MESSAGE:
        return write_message(fd, data);
    case SESSION:
        break;
    }
}

bool check_type(char **args, enum data_type expected_type) {
    if (!args)
        return false;
    if (((enum data_type) atoi(args[0])) != expected_type)
        return false;
    return true;
}