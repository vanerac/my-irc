/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** read_team
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