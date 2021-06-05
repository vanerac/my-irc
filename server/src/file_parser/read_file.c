/*
** EPITECH PROJECT, 2021
** C
** File description:
** read_file.c file
*/

#include <unistd.h>
#include <logging_server.h>
#include "file_parser.h"

t_teams *parse_team(char **args)
{
    t_teams *ret = malloc(sizeof(t_teams));
    if (!check_type(args, TEAM))
        return NULL;
    // todo check args count
    // read meta data
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];
    ret->channels = NULL;

    return ret;
}

t_channel *parse_channel(char **args)
{

    t_channel *ret = malloc(sizeof(t_channel));
    if (!check_type(args, CHANNEL))
        return NULL;
    // todo check size
    ret->type = CHANNEL;
    uuid_parse(args[1], ret->uid);
    ret->name = args[2], ret->desc = args[3];
    ret->messages = NULL;
    return ret;
}

t_messages *parse_thread(char **args)
{
    t_messages *ret = malloc(sizeof(t_messages));

    if (!check_type(args, THREAD))
        return NULL;
    ret->type = MESSAGE;
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

    if (!check_type(args, MESSAGE))
        return NULL;
    ret->type = MESSAGE;
    uuid_parse(args[2], ret->uid);
    ret->created_at = atoll(
        args[3]), ret->title = args[4], ret->body = args[5], ret->m_type = atoi(
        args[1]);
    return ret;
}

t_user *parse_user(char **args)
{
    t_user *ret = malloc(sizeof(t_user));

    if (!check_type(args, USER))
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
    if (!check_type(args, USER))
        return NULL;
    t_dm *ret = malloc(sizeof(t_dm));

    ret->type = DM;
    uuid_parse(args[1], ret->user_second);
    uuid_parse(args[2], ret->user_first);

    list_t *message = NULL;
    ret->messages = message;

    return ret;
}