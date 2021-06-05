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
        case UNKNOWN:
            return ret;
        case USER:
            current_user =  parse_user(args);
            if (!ret)
                ret = node_list_create(current_user);
            else
                node_append_data(ret, current_user);
            break;
        case TEAM:
            current_channel = NULL, current_thread = NULL;
            current_team = parse_team(args);
            if (!ret)
                ret = node_list_create(current_team);
            else
                node_append_data(ret, current_team);
            break;
        case CHANNEL:
            current_thread = NULL;
            current_channel = parse_channel(args);
            if (!current_team )
                return NULL;
            if (current_team->channels)
                node_append_data(current_team->channels, current_channel);
            else
                current_team->channels = node_list_create(current_channel);
            break;
        case THREAD:
            current_thread = parse_thread(args);
            if (!current_channel )
                return NULL;
            if (current_channel->messages)
                node_append_data(current_channel->messages, current_thread);
            else
                current_channel->messages = node_list_create(current_thread);
            break;
        case REPLY: {
            t_messages *m = parse_reply(args);
            if (!current_thread)
                return NULL;
            if (current_thread->replies)
                node_append_data(current_thread->replies, m);
            else
                current_thread->replies = node_list_create(m);
            break;
        }
        case DM:
            current_dm =  parse_dm(args);
            if (!ret)
                ret = node_list_create(current_dm);
            else
                node_append_data(ret, current_dm);
            break;
        case MESSAGE: {
            t_messages *m = parse_reply(args);
            if (!current_dm)
                return NULL;
            if (current_dm->messages)
                node_append_data(current_dm->messages, m);
            else
                current_dm->messages = node_list_create(m);
            break;
        }
        default:
            return ret;
        }
    }
    return ret;
}