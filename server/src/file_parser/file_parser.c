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

    for (char **args = NULL; (args = get_args(fd, true));) {
        if ((enum data_type)atoi(args[0]) == USER)
            case_USER(args, &ret);
        if ((enum data_type)atoi(args[0]) == DM)
            case_DM(args, &current_dm, &ret);
        if ((enum data_type)atoi(args[0]) == MESSAGE){
            if (case_MESSAGE(args, &current_dm) == 84)
                return NULL;
        }
    }
    return ret;
}

void *parse_file_bis(char **args, list_t **ret)
{
    static t_teams *current_team = NULL;
    static t_channel *current_channel = NULL;
    static t_messages *current_thread = NULL;

    if ((enum data_type)atoi(args[0]) == CHANNEL) {
        if (case_CHANNEL(args, &current_team, &current_channel, &current_thread) == 84)
            return NULL;
    }
    if ((enum data_type)atoi(args[0]) == THREAD) {
        if (case_THREAD(args, &current_thread, &current_channel) == 84)
            return NULL;
    }
    if ((enum data_type)atoi(args[0]) == TEAM) {
        current_channel = NULL, current_thread = NULL;
        case_TEAM(args, &current_team, ret);
    }
    if ((enum data_type)atoi(args[0]) == REPLY) {
        if (case_REPLY(args, &current_thread) == 84)
            return NULL;
    }
    return NULL;
}