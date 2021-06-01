/*
** EPITECH PROJECT, 2021
** C
** File description:
** write_file.c file
*/

#include "file_parser.h"

void write_user(int fd, t_user *user)
{
    dprintf(fd, "%d %s \"%s\"\n", user->type, user->uid, user->username);
}

void write_message(int fd, t_messages *messages)
{
    dprintf(fd, "%d %u %s \"%s\" \"%s\"\n", messages->type, messages->m_type,
        messages->uid, messages->title, messages->body);
}

void write_thread(int fd, t_messages *thread, int recursion_levels)
{
    dprintf(fd, "%d %u %s \"%s\" \"%s\"\n", thread->type, thread->m_type,
        thread->uid, thread->title, thread->body);
    for (list_t *message = thread->replies;
        message && recursion_levels > 0; message = message->next) {
        write_message(fd, message->data);
    }
    dprintf(fd, "%d\n", END_STRUCT);
}

void write_channel(int fd, t_channel *channel, int recursion_levels)
{
    dprintf(fd, "%d %s \"%s\" \"%s\"\n", channel->type, channel->uid,
        channel->name, channel->desc);
    for (list_t *tread = channel->messages;
        tread && recursion_levels > 0; tread = tread->next) {
        write_thread(fd, tread->data, recursion_levels - 1);
    }
    dprintf(fd, "%d\n", END_STRUCT);
}

void write_team(int fd, t_teams *team, int recursion_levels)
{
    dprintf(fd, "%d %s \"%s\" \"%s\"\n", team->type, team->uid, team->name,
        team->desc);
    for (list_t *channel = team->channels;
        channel && recursion_levels > 0; channel = channel->next) {
        write_channel(fd, channel->data, recursion_levels - 1);
    }
    for (list_t *users = team->users;
        users && recursion_levels > 0; users = users->next) {
        write_user(fd, users->data);
    }
    dprintf(fd, "%d\n", END_STRUCT);
}



