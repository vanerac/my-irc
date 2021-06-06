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
    t_user *current_user = NULL;

    for (char **args = NULL; (args = get_args(fd, true));) {
        switch ((enum data_type) atoi(args[0])) {
        case USER:
            current_user = parse_user(args);
            NODE_ADD(ret, current_user)
            break;
        case TEAM:
            current_channel = NULL, current_thread = NULL;
            current_team = parse_team(args);
            NODE_ADD(ret, current_team)
            break;
        case CHANNEL:
            current_thread = NULL;
            current_channel = parse_channel(args);
            if (!current_team)
                return NULL;
            NODE_ADD(current_team->channels, current_channel)
            break;
        case THREAD:
            current_thread = parse_thread(args);
            if (!current_channel)
                return NULL;
            NODE_ADD(current_channel->messages, current_thread)
            break;
        case REPLY: {
            t_messages *m = parse_reply(args);
            if (!current_thread)
                return NULL;
            NODE_ADD(current_thread->replies, m)
            break;
        }
        case DM:
            current_dm = parse_dm(args);
            NODE_ADD(ret, current_dm)
            break;
        case MESSAGE: {
            if (!current_dm)
                return NULL;
            t_messages *m = parse_reply(args);
            m->type = MESSAGE;
            NODE_ADD(current_dm->messages, m)
            break;
        }
        default:
            return ret;
        }
    }
    return ret;
}