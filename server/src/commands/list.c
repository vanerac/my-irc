/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include <logging_server.h>
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

static enum command_return dump_messages(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;
    char *print = strdup("204 ");
    for (list_t *node = session->current_thread->replies; node; node = node->next) {
        t_channel *channel = node->data;
        char uuid[37];
        uuid_unparse(channel->uid, uuid);

        if (print)
            asprintf(&buffer, "%s%s \"%s\" \"%s\"\n", print, uuid,
                channel->name, channel->desc);
        else
            asprintf(&buffer, "202 %s \"%s\" \"%s\"\n", uuid, channel->name,
                channel->desc);
        free(print);
        print = strdup(buffer);
    }
    send_message(session->socket, print, RESPONSE, LIST);
    return SUCCESS;
}

static enum command_return dump_threads(t_global *global, session_t *session)
{
    (void) global, (void) session;
    char *buffer = NULL;
    char *print = strdup("203 ");

    if (!print)
        return SYSTEM_ERROR;
    for (list_t *node = session->current_channel->messages; node; node = node->next) {
        t_messages *thread = node->data;
        char t_uuid[37];
        char u_uuid[37];
        uuid_unparse(thread->uid, t_uuid);
        asprintf(&buffer, "%s%s %s %lud \"%s\" \"%s\"\n", print, t_uuid,
            u_uuid, thread->created_at, thread->title, thread->body);

        free(print);
        print = strdup(buffer);
        if (!print)
            return SYSTEM_ERROR;
    }
    send_message(session->socket, print, RESPONSE, LIST);
    return SUCCESS;
}

static enum command_return dump_channels(t_global *global, session_t *session)
{
    (void) global;
    char *buffer = NULL;
    char *print = strdup("202 ");
    for (list_t *node = session->current_team->channels; node; node = node->next) {
        t_channel *channel = node->data;
        char uuid[37];
        uuid_unparse(channel->uid, uuid);

        asprintf(&buffer, "%s%s \"%s\" \"%s\"\n", print, uuid, channel->name,
            channel->desc);
        free(print);
        print = strdup(buffer);
    }
    send_message(session->socket, print, RESPONSE, LIST);
    return SUCCESS;
}

static enum command_return dump_teams(t_global *global, session_t *session)
{
    char *buffer = NULL;
    char *print = strdup("201 ");
    for (list_t *node = global->teams; node; node = node->next) {
        t_teams *team = node->data;
        char uuid[37];
        uuid_unparse(team->uid, uuid);

        asprintf(&buffer, "%s%s \"%s\" \"%s\"\n", print, uuid, team->name,
            team->desc);

        free(print);
        print = strdup(buffer);
    }
    send_message(session->socket, print, RESPONSE, LIST);
    return SUCCESS;
}

void command_list(t_global *global, session_t *session, char **args
)
{
    (void) args, (void) global, (void) session;
    (void) dump_channels, (void) dump_messages, (void) dump_teams, (void) dump_threads;
    //    if (session->current_thread)
    //        return dump_messages(global, session);
    //    if (session->current_channel)
    //        return dump_threads(global, session);
    //    if (session->current_team)
    //        return dump_channels(global, session);
    //    return dump_teams(global, session);
}