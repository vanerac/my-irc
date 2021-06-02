/*
** EPITECH PROJECT, 2021
** C
** File description:
** create.c file
*/

#include <server.h>
#include <commands.h>
#include <string.h>
#include <logging_server.h>

static enum command_return create_team(t_global *global, char *name, char *desc
)
{
    t_teams *team = malloc(sizeof(t_teams));
    char *uuid = NULL;
    if (!team)
        return SYSTEM_ERROR;
    uuid_generate(team->uid);
    team->name = strdup(name);
    team->desc = strdup(desc);
    team->channels = NULL;
    team->type = TEAM;
    team->users = NULL;
    uuid_unparse(team->uid, uuid);
    server_event_team_created(uuid, name, desc);
    if (global->teams)
        return node_append_data(global->teams, team) ? SUCCESS : SYSTEM_ERROR;
    else
        return (global->teams = node_list_create(team)) ? SUCCESS :
            SYSTEM_ERROR;
}

static enum command_return create_channel(t_teams *team, char *arg, char *arg1)
{
    t_channel *channel = malloc(sizeof(t_channel));
    char *uuid = NULL;
    if (!channel)
        return SYSTEM_ERROR;
    channel->type = CHANNEL;
    channel->name = arg;
    channel->desc = arg1;
    uuid_generate(channel->uid);
    uuid_unparse(channel->uid, uuid);
    channel->messages = NULL;
    server_event_channel_created((char const *) team->uid, uuid,
        channel->name);
    if (team->channels)
        return node_append_data(team->channels, channel) ? SUCCESS :
            SYSTEM_ERROR;
    else
        return (team->channels = node_list_create(channel)) ? SUCCESS :
            SYSTEM_ERROR;
}

static enum command_return create_tread(t_channel *pChannel,
    session_t *session, char *arg, char *arg1
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char *uuid_t = NULL, *uuid_s = NULL;
    if (!thread)
        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = THREAD;
    thread->m_type = M_THREAD;
    thread->body = arg1;
    thread->title = arg;
    thread->destination = pChannel;
    thread->source = session->user_data;
    thread->replies = NULL;
    uuid_unparse(thread->uid, uuid_t);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_thread_created((char const *) pChannel->uid, uuid_t, uuid_s,
        thread->title, thread->body);
    if (pChannel->messages)
        return node_append_data(pChannel->messages, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        return (pChannel->messages = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
}

static enum command_return create_comment(t_messages *pMessages,
    session_t *session, char *arg
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char *uuid_m = NULL, *uuid_s = NULL;
    if (!thread)
        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = REPLY;
    thread->m_type = M_REPLY;
    thread->title = NULL;
    thread->body = arg;
    thread->destination = pMessages;
    thread->source = session->user_data;
    thread->replies = NULL;
    uuid_unparse(pMessages->uid, uuid_m);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_thread_new_reply(uuid_m, uuid_s, thread->body);
    if (pMessages->replies)
        return node_append_data(pMessages->replies, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        return (pMessages->replies = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
}

enum command_return command_create(t_global *global, session_t *session,
    char **args
)
{
    (void) args; // todo parse args
    char *first_arg = NULL, *second_arg = NULL; // todo
    if (!session->current_team) {
        return create_team(global, first_arg, second_arg);;
    } else if (!session->current_channel) {
        return create_channel(session->current_team, first_arg, second_arg);
    }
    if (!session->current_thread) {
        return create_tread(session->current_channel, session, first_arg,
            second_arg);
    } else {
        return create_comment(session->current_thread, session, first_arg);
    }
}