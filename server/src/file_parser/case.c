/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** case
*/

#include "file_parser.h"

int case_MESSAGE(char **args, t_dm *current_dm)
{
    if (!current_dm)
        return 84;
    t_messages *m = parse_reply(args);
    m->type = MESSAGE;
    NODE_ADD(current_dm->messages, m);
    return 0;
}

void case_DM(char **args, t_dm *current_dm)
{
    list_t *ret = NULL;

    current_dm = parse_dm(args);
    NODE_ADD(ret, current_dm);
}

int case_REPLY(char **args, t_messages *current_thread)
{
    t_messages *m = parse_reply(args);
    if (!current_thread)
        return 84;
    NODE_ADD(current_thread->replies, m);
    return 0;
}

int case_THREAD(char **args, t_messages *current_thread,
t_channel *current_channel)
{
    current_thread = parse_thread(args);
    if (!current_channel)
        return 84;
    NODE_ADD(current_channel->messages, current_thread);
    return 0;
}

void case_TEAM(char **args, t_teams *current_team, t_channel **current_channel,
t_messages **current_thread)
{
    list_t *ret = NULL;
    *current_channel = NULL, *current_thread = NULL;

    current_team = parse_team(args);
    NODE_ADD(ret, current_team);
}

int case_CHANNEL(char **args, t_teams *current_team, t_channel *current_channel,
t_messages **current_thread)
{
    *current_thread = NULL;
    current_channel = parse_channel(args);
    if (!current_team)
        return 84;
    NODE_ADD(current_team->channels, current_channel);
    return 0;
}

void case_USER(char **args)
{
    t_user *current_user = NULL;
    list_t *ret = NULL;

    current_user = parse_user(args);
    NODE_ADD(ret, current_user)
}