/*
** EPITECH PROJECT, 2021
** C
** File description:
** read_file.c file
*/

#include <unistd.h>
#include <logging_server.h>
#include "file_parser.h"

t_teams *file_read_team(int fd, int recursion_level)
{
    (void) recursion_level;
    char **args = get_args(fd, false);
    t_teams *ret = malloc(sizeof(t_teams));

    if (!check_type(args, TEAM)) {
        args = get_args(fd, true);
        if (!check_type(args, TEAM))
            return NULL;
    }
    // todo check args count
    // read meta data
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];
    list_t *channels = NULL;
    list_t *users = NULL;
    for (void *data = NULL; (data = file_read_channel(fd,
        recursion_level - 1));)
        if (!channels)
            channels = node_list_create(data);
        else
            node_append_data(channels, data);

    ret->channels = channels;
    for (void *data = NULL; (data = file_read_user(fd));)
        if (!users)
            users = node_list_create(data);
        else
            node_append_data(users, data);

    ret->users = users;

    return ret;
}

t_channel *file_read_channel(int fd, int recursion_level)
{
    (void) recursion_level;
    char **args = get_args(fd, false);
    t_channel *ret = malloc(sizeof(t_teams));

    if (!check_type(args, CHANNEL)) {
        args = get_args(fd, true);
        if (!check_type(args, CHANNEL))
            return NULL;
    }
    // todo check size
    ret->type = CHANNEL;
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];

    list_t *threads = NULL;
    for (void *data = NULL; (data = file_read_thread(fd,
        recursion_level - 1));)
        if (!threads)
            threads = node_list_create(data);
        else
            node_append_data(threads, data);

    ret->messages = threads;

    return ret;
}

t_messages *file_read_thread(int fd, int recursion_level)
{
    (void) recursion_level;
    char **args = get_args(fd, false);
    t_messages *ret = malloc(sizeof(t_teams));

    if (!check_type(args, THREAD)) {
        args = get_args(fd, true);
        if (!check_type(args, THREAD))
            return NULL;
    }
    // todo check size
    ret->type = MESSAGE;
    uuid_parse(args[2], ret->uid);
    ret->created_at = atoll(
        args[3]), ret->title = args[4], ret->body = args[5], ret->m_type = atoi(
        args[1]);

    list_t *replies = NULL;
    for (void *data = NULL; (data = file_read_message(fd));)
        if (!replies)
            replies = node_list_create(data);
        else
            node_append_data(replies, data);

    ret->replies = replies;

    return ret;
}

t_messages *file_read_message(int fd)
{
    char **args = get_args(fd, false);
    t_messages *ret = malloc(sizeof(t_teams));

    if (!check_type(args, MESSAGE)) {
        args = get_args(fd, true);
        if (!check_type(args, MESSAGE))
            return NULL;
    }
    // todo check size
    // read meta data
    ret->type = MESSAGE;
    uuid_parse(args[2], ret->uid);
    ret->created_at = atoll(
        args[3]), ret->title = args[4], ret->body = args[5], ret->m_type = atoi(
        args[1]);
    return ret;
}

t_user *file_read_user(int fd)
{
    char **args = get_args(fd, false);
    t_user *ret = malloc(sizeof(t_teams));

    if (!check_type(args, USER)) {
        args = get_args(fd, true);
        if (!check_type(args, USER))
            return NULL;
    }
    // todo check size
    // read meta data
    ret->type = USER;
    uuid_parse(args[1], ret->uid);
    ret->username = args[2];
    ret->logged = false;
    char uuid[37];
    uuid_unparse(ret->uid, uuid);
    server_event_user_loaded(uuid, ret->username); // todo maybe change place
    return NULL;
}