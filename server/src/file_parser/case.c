/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** case
*/

#include "file_parser.h"

int case_MESSAGE(char **args, t_dm **current_dm)
{
    if (!*current_dm)
        return 84;
    t_messages *m = parse_reply(args);
    if (!m)
        return 84;
    m->type = MESSAGE;
    NODE_ADD((*current_dm)->messages, m);
    return 0;
}

void case_DM(char **args, t_dm **current_dm, list_t **ret)
{
    *current_dm = parse_dm(args);
    NODE_ADD(ret, *current_dm);
}

int case_REPLY(char **args, t_messages **current_thread)
{
    t_messages *m = parse_reply(args);
    if (!*current_thread)
        return 84;
    NODE_ADD((*current_thread)->replies, m);
    return 0;
}

int case_THREAD(char **args, t_messages **current_thread,
t_channel **current_channel)
{
    *current_thread = parse_thread(args);
    if (!current_channel)
        return 84;
    NODE_ADD((*current_channel)->messages, *current_thread);
    return 0;
}