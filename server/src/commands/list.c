/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

static enum command_return dump_messages(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;

    for (list_t *node = session->current_thread->replies;
        node != NULL; node = node->next) {
        t_channel *channel = node->data;
        char uuid[37];
        uuid_unparse(channel->uid, uuid);

        asprintf(&buffer, "204 \"%s\" \"%s\" \"%s\"\n", uuid, channel->name,
            channel->desc);

        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }
    return SUCCESS;
}

static enum command_return dump_threads(t_global *global, session_t *session)
{
    (void) global, (void) session;
    char *buffer = NULL;

    for (list_t *node = session->current_channel->messages;
        node != NULL; node = node->next) {
        t_messages *thread = node->data;
        char t_uuid[37];
        char u_uuid[37];
        uuid_unparse(thread->uid, t_uuid);
        asprintf(&buffer, "203 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\n", t_uuid,
            u_uuid, thread->created_at, thread->title, thread->body);

        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }

    return SUCCESS;
}

static enum command_return dump_channels(t_global *global, session_t *session)
{
    char *buffer = NULL;
    (void) global;

    for (list_t *node = session->current_team->channels;
        node != NULL; node = node->next) {
        t_channel *channel = node->data;
        char uuid[37];
        uuid_unparse(channel->uid, uuid);

        asprintf(&buffer, "202 \"%s\" \"%s\" \"%s\"\n", uuid, channel->name,
            channel->desc);
        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }

    return SUCCESS;
}

static enum command_return dump_teams(t_global *global, session_t *session)
{
    char *buffer = NULL;
    char uuid[37];

    for (list_t *node = global->teams; node != NULL; node = node->next) {
        t_teams *team = (t_teams *) node->data;
        uuid_unparse(team->uid, uuid);
        asprintf(&buffer, "201 \"%s\" \"%s\" \"%s\"\n", uuid, team->name,
            team->desc);
        send_message(session->socket, buffer, RESPONSE, LIST);
        free(buffer);
    }

    return SUCCESS;
}

enum command_return call_list(t_global *global, session_t *session)
{
    if (session->current_thread)
        return dump_messages(global, session);
    if (session->current_channel)
        return dump_threads(global, session);
    if (session->current_team)
        return dump_channels(global, session);
    else
        return dump_teams(global, session);
}

void command_list(t_global *global, session_t *session, char **args)
{
    (void) args, (void) global;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    /*return_val = */call_list(global, session);
}