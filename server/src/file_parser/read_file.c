/*
** EPITECH PROJECT, 2021
** C
** File description:
** read_file.c file
*/

#include <unistd.h>
#include "file_parser.h"

// todo
//  - handle corrupted file format
//  - handle "" and "\n"
//  functions parse current line, if current line doesnt correspond, error




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
    // read channels
//    list_t *channels = NULL;
//    list_t *users = NULL;
//    for () {
//    }
//    ret->channels = channels;
//    for () {
//    }
//    ret->users = users;

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

     //todo // for recursion level, read threads
//     ret->messages;

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
    ret->title = args[3], ret->body = args[3], ret->m_type = atoi(args[1]);

    //todo
//    ret->replies;

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
    ret->title = args[3], ret->body = args[4],
    ret->m_type = atoi(args[1]);
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
    return NULL;
}