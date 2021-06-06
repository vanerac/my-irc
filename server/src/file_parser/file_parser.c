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
    case DM:
        return write_dm(fd, data, recursion_levels);
    default:
        break;
    }
}

bool check_type(char **args, enum data_type expected_type)
{
    if (!args)
        return false;
    if (((enum data_type) atoi(args[0])) != expected_type)
        return false;
    return true;
}

list_t *parse_file(int fd)
{
    list_t *ret = NULL;
    t_dm *current_dm = NULL;
    t_teams *current_team = NULL;
    t_channel *current_channel = NULL;
    t_messages *current_thread = NULL;

    for (char **args = NULL; (args = get_args(fd, true));) {
        switch ((enum data_type) atoi(args[0])) {
        case USER:
            case_USER(args, &ret);
            break;
        case TEAM:
            current_channel = NULL, current_thread = NULL;
            case_TEAM(args, &current_team, &ret);
            break;
        case CHANNEL:
            if (case_CHANNEL(args, &current_team, &current_channel, &current_thread) == 84)
                return NULL;
            break;
        case THREAD:
            if (case_THREAD(args, &current_thread, &current_channel) == 84)
                return NULL;
            break;
        case REPLY:
            if (case_REPLY(args, &current_thread) == 84)
                return NULL;
            break;
        case DM:
            case_DM(args, &current_dm, &ret);
            break;
        case MESSAGE:
            if (case_MESSAGE(args, &current_dm) == 84)
                return NULL;
            break;
        default:
            return ret;
        }
    }
    return ret;
}