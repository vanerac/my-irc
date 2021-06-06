/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** case_bis
*/

#include "file_parser.h"

void case_TEAM(char **args, t_teams **current_team, list_t **ret)
{
    *current_team = parse_team(args);
    NODE_ADD(*ret, *current_team);
}

int case_CHANNEL(char **args, t_teams **current_team, t_channel **current_channel,
t_messages **current_thread)
{
    *current_thread = NULL;
    *current_channel = parse_channel(args);
    if (!current_team)
        return 84;
    NODE_ADD((*current_team)->channels, *current_channel);
    return 0;
}

void case_USER(char **args)
{
    t_user *current_user = NULL;
    list_t *ret = NULL;

    current_user = parse_user(args);
    NODE_ADD(ret, current_user)
}