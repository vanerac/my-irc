/*
** EPITECH PROJECT, 2021
** C
** File description:
** write_file.c file
*/

#include "file_parser.h"

void write_user(int fd, t_user *user)
{
    char uuid[37] ;
    uuid_unparse(user->uid, uuid);
    dprintf(fd, "%d %s \"%s\"\n", user->type, uuid, user->username);
}

void write_message(int fd, t_messages *messages)
{
    char uuid[37] ;
    uuid_unparse(messages->uid, uuid);
    dprintf(fd, "%d %u %s %lud \"%s\" \"%s\"\n", messages->type,
        messages->m_type, uuid, messages->created_at, messages->title,
        messages->body);
}

void write_thread(int fd, t_messages *thread, int recursion_levels)
{
    char uuid[37] ;
    uuid_unparse(thread->uid, uuid);
    dprintf(fd, "%d %u %s %lud \"%s\" \"%s\"\n", thread->type, thread->m_type,
        uuid, thread->created_at, thread->title, thread->body);
    for (list_t *message = thread->replies;
        message && recursion_levels > 0; message = message->next) {
        write_message(fd, message->data);
    }
//    dprintf(fd, "%d\n", END_STRUCT);
}

void write_channel(int fd, t_channel *channel, int recursion_levels)
{
    char uuid[37] ;
    uuid_unparse(channel->uid, uuid);
    dprintf(fd, "%d \"%s\" \"%s\"\n", channel->type, uuid,
        channel->desc);
    for (list_t *tread = channel->messages;
        tread && recursion_levels > 0; tread = tread->next) {
        write_thread(fd, tread->data, recursion_levels - 1);
    }
//    dprintf(fd, "%d\n", END_STRUCT);
}

void write_team(int fd, t_teams *team, int recursion_levels)
{
    char uuid[37] ;
    uuid_unparse(team->uid, uuid);
    dprintf(fd, "%d \"%s\" \"%s\" \"%s\"\n", team->type, uuid, team->name,
        team->desc);
    for (list_t *channel = team->channels;
        channel && recursion_levels > 0; channel = channel->next) {
        write_channel(fd, channel->data, recursion_levels - 1);
    }
    //    for (list_t *users = team->users;
    //        users && recursion_levels > 0; users = users->next) {
    //        write_user(fd, users->data);
    //    }
//    dprintf(fd, "%d\n", END_STRUCT);
}

void write_dm(int fd, t_dm *dm, int recursion_level)
{
    char uuid_first[37];
    char uuid_second[37];
    uuid_unparse(dm->user_second, uuid_second);
    uuid_unparse(dm->user_first, uuid_first);

    dprintf(fd, "%d \"%s\" \"%s\"\n", dm->type, uuid_first, uuid_second);

    for (list_t *message = dm->messages;
        recursion_level > 0 && message; message = message->next) {
        write_message(fd, message->data);
    }
//    dprintf(fd, "%d\n", END_STRUCT);
}


