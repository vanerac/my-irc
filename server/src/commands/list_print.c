/*
** EPITECH PROJECT, 2021
** print function for list
** File description:
** list_print
*/

#include "logging_server.h"
#include "commands.h"
#include "message.h"

enum command_return dump_messages(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;
    t_channel *channel = NULL;
    char uuid[37];

    for (list_t *node = session->current_thread->replies;
        node != NULL; node = node->next) {
        channel = node->data;
        uuid_unparse(channel->uid, uuid);
        asprintf(&buffer, "204 \"%s\" \"%s\" \"%s\"\n", uuid, channel->name,
            channel->desc);
        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }
    return SUCCESS;
}

enum command_return dump_threads(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;
    t_messages *thread = NULL;
    char t_uuid[37];
    char u_uuid[37];

    for (list_t *node = session->current_channel->messages;
        node != NULL; node = node->next) {
        thread = node->data;
        uuid_unparse(thread->uid, t_uuid);
        uuid_unparse(thread->author->uid, u_uuid);
        asprintf(&buffer, "203 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\n", t_uuid,
            u_uuid, thread->created_at, thread->title, thread->body);

        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }

    return SUCCESS;
}

enum command_return dump_channels(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;
    t_channel *channel = NULL;
    char uuid[37];

    for (list_t *node = session->current_team->channels;
        node != NULL; node = node->next) {
        channel = node->data;
        uuid_unparse(channel->uid, uuid);
        asprintf(&buffer, "202 \"%s\" \"%s\" \"%s\"\n", uuid, channel->name,
            channel->desc);
        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }
    return SUCCESS;
}

enum command_return dump_teams(t_global *global, session_t *session)
{
    char *buffer = NULL;
    char uuid[37];
    t_teams *team = NULL;

    for (list_t *node = global->teams; node != NULL; node = node->next) {
        team = (t_teams *) node->data;
        uuid_unparse(team->uid, uuid);
        asprintf(&buffer, "201 \"%s\" \"%s\" \"%s\"\n", uuid, team->name,
            team->desc);
        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }
    return SUCCESS;
}