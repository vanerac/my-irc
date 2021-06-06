/*
** EPITECH PROJECT, 2021
** C
** File description:
** write_file.c file
*/

#include "file_parser.h"

void write_user(int fd, t_user *user)
{
    char uuid[37];
    uuid_unparse(user->uid, uuid);
    dprintf(fd, "\"%d\" \"%s\" \"%s\"\n", user->type, uuid, user->username);
}

void write_message(int fd, t_messages *messages)
{
    char uuid[37], author_uuid[37];
    uuid_unparse(messages->uid, uuid);
    uuid_unparse(messages->author_uuid, author_uuid);
    dprintf(fd, "\"%d\" \"%u\" \"%s\" \"%s\" \"%lud\" \"%s\" \"%s\"\n",
        messages->type, messages->m_type, uuid, author_uuid, messages->created_at,
        messages->title, messages->body);
}

void write_dm(int fd, t_dm *dm, int recursion_level)
{
    char uuid_first[37];
    char uuid_second[37];
    uuid_unparse(dm->user_second, uuid_second);
    uuid_unparse(dm->user_first, uuid_first);

    dprintf(fd, "\"%d\" \"%s\" \"%s\"\n", dm->type, uuid_first, uuid_second);

    for (list_t *message = dm->messages;
        recursion_level > 0 && message; message = message->next) {
        write_message(fd, message->data);
    }
}