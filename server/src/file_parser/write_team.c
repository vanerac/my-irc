/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** write_team
*/

#include "file_parser.h"

void write_thread(int fd, t_messages *thread, int recursion_levels)
{
    char uuid[37];
    uuid_unparse(thread->uid, uuid);
    dprintf(fd, "\"%d\" \"%u\" \"%s\" \"%lud\" \"%s\" \"%s\"\n", thread->type,
        thread->m_type, uuid, thread->created_at, thread->title, thread->body);
    for (list_t *message = thread->replies;
        message && recursion_levels > 0; message = message->next) {
        write_message(fd, message->data);
    }
}

void write_channel(int fd, t_channel *channel, int recursion_levels)
{
    char uuid[37];
    uuid_unparse(channel->uid, uuid);
    dprintf(fd, "\"%d\" \"%s\" \"%s\" \"%s\"\n", channel->type, uuid,
        channel->name, channel->desc);
    for (list_t *tread = channel->messages;
        tread && recursion_levels > 0; tread = tread->next) {
        write_thread(fd, tread->data, recursion_levels - 1);
    }
}

void write_team(int fd, t_teams *team, int recursion_levels)
{
    char uuid[37];
    uuid_unparse(team->uid, uuid);
    dprintf(fd, "\"%d\" \"%s\" \"%s\" \"%s\"\n", team->type, uuid, team->name,
        team->desc);
    for (list_t *channel = team->channels;
        channel && recursion_levels > 0; channel = channel->next) {
        write_channel(fd, channel->data, recursion_levels - 1);
    }
}