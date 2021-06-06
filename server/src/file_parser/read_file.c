/*
** EPITECH PROJECT, 2021
** C
** File description:
** read_file.c file
*/

#include <unistd.h>
#include <logging_server.h>
#include <server.h>
#include "file_parser.h"

t_teams *parse_team(char **args)
{
    t_teams *ret = malloc(sizeof(t_teams));
    if (!check_type(args, TEAM) || !args_len(args, 4))
        return NULL;
    ret->type = TEAM;
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];
    ret->channels = NULL;
    ret->subscribers = NULL;
    ret->users = NULL;

    return ret;
}

t_channel *parse_channel(char **args)
{

    t_channel *ret = malloc(sizeof(t_channel));
    if (!check_type(args, CHANNEL) || !args_len(args, 4))
        return NULL;
    ret->type = CHANNEL;
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];
    ret->messages = NULL;
    return ret;
}

t_messages *parse_thread(char **args)
{
    t_messages *ret = malloc(sizeof(t_messages));

    if (!check_type(args, THREAD) || !args_len(args, 6))
        return NULL;
    ret->type = THREAD;
    uuid_parse(args[2], ret->uid);
    ret->created_at = atoll(
        args[3]), ret->title = args[4], ret->body = args[5], ret->m_type = atoi(
        args[1]);

    list_t *replies = NULL;
    ret->replies = replies;
    return ret;
}

t_messages *parse_reply(char **args)
{
    t_messages *ret = malloc(sizeof(t_messages));

    if (!check_type(args, MESSAGE) || !args_len(args, 7))
        return NULL;
    ret->type = REPLY;
    uuid_parse(args[2], ret->uid);
    uuid_parse(args[3], ret->author_uuid);
    ret->created_at = atoll(
        args[4]), ret->title = args[5], ret->body = args[6], ret->m_type = atoi(
        args[1]);
    return ret;
}

t_user *parse_user(char **args)
{
    t_user *ret = malloc(sizeof(t_user));

    if (!check_type(args, USER) || !args_len(args, 3))
        return NULL;
    ret->type = USER;
    uuid_parse(args[1], ret->uid);
    ret->username = args[2];
    ret->logged = false;
    char uuid[37];
    uuid_unparse(ret->uid, uuid);
    server_event_user_loaded(uuid, ret->username); // todo maybe change place
    return ret;
}

t_dm *parse_dm(char **args)
{
    if (!check_type(args, DM) || !args_len(args, 3))
        return NULL;
    t_dm *ret = malloc(sizeof(t_dm));

    ret->type = DM;
    uuid_parse(args[1], ret->user_second);
    uuid_parse(args[2], ret->user_first);

    list_t *message = NULL;
    ret->messages = message;

    return ret;
}