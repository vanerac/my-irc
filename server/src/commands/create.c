/*
** EPITECH PROJECT, 2021
** C
** File description:
** create.c file
*/

#include <string.h>
#include "logging_server.h"
#include "server.h"
#include "commands.h"
#include "message.h"

// todo handle duplicates
int asprintf(char **restrict strp, const char *restrict fmt, ...);

static enum command_return create_team_second_part(t_global *global,
    session_t *session, t_teams *team, char *uuid
)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;

    if (global->teams)
        ret_val =
            node_append_data(global->teams, team) ? SUCCESS : SYSTEM_ERROR;
    else
        ret_val =
            (global->teams = node_list_create(team)) ? SUCCESS : SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    asprintf(&ret, "206 \"%s\" \"%s\" \"%s\"", uuid, team->name, team->desc);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    // to do notify all user subscribed to this team
    return SUCCESS;
}

static enum command_return create_team(t_global *global, session_t *session,
    char *name, char *desc
)
{
    t_teams *team = malloc(sizeof(t_teams));
    char uuid[37];
    if (!team)
        return SYSTEM_ERROR;
    uuid_generate(team->uid);
    team->name = strdup(name);
    team->desc = strdup(desc);
    team->channels = NULL;
    team->type = TEAM;
    team->users = NULL;
    uuid_unparse(team->uid, uuid);
    server_event_team_created(uuid, name,
        ((t_user *) session->user_data)->username);
    return create_team_second_part(global, session, team, uuid);
}

static enum command_return create_channel_second_part(t_teams *team,
    session_t *session, t_channel *channel, char *uuid
)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;

    if (team->channels)
        ret_val =
            node_append_data(team->channels, channel) ? SUCCESS : SYSTEM_ERROR;
    else
        ret_val = (team->channels = node_list_create(channel)) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    asprintf(&ret, "208 \"%s\" \"%s\" \"%s\"", uuid, channel->name, channel->desc);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    return SUCCESS;
}

static enum command_return create_channel(t_teams *team, session_t *session,
    char *arg, char *arg1
)
{
    t_channel *channel = malloc(sizeof(t_channel));
    char uuid[37];
    char t_uuid[37];
    if (!channel)
        return SYSTEM_ERROR;
    channel->type = CHANNEL;
    channel->name = arg;
    channel->desc = arg1;
    uuid_generate(channel->uid);
    uuid_unparse(channel->uid, uuid);
    uuid_unparse(team->uid, t_uuid);
    channel->messages = NULL;
    server_event_channel_created(t_uuid, uuid, channel->name);
    return create_channel_second_part(team, session, channel, uuid);
}

static enum command_return create_thread_second_part(t_channel *pchannel,
    session_t *session, t_messages *thread
)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;
    char t_uuid[37];
    char s_uuid[37];
    if (pchannel->messages)
        ret_val = node_append_data(pchannel->messages, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (pchannel->messages = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    uuid_unparse(((t_user *) session->user_data)->uid, s_uuid);
    uuid_unparse(thread->uid, t_uuid);
    asprintf(&ret, "210 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"", t_uuid, s_uuid,
        thread->created_at, thread->title, thread->body);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    return SUCCESS;
}

static enum command_return create_tread(t_channel *pchannel,
    session_t *session, char *arg, char *arg1
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char uuid_t[37], uuid_s[37], uuid_c[37];
    if (!thread)
        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = THREAD;
    thread->m_type = M_THREAD;
    thread->body = arg1;
    thread->title = arg;
    thread->destination = pchannel;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_unparse(thread->uid, uuid_t);
    uuid_unparse(session->user_data->uid, uuid_s);
    uuid_unparse(pchannel->uid, uuid_c);
    server_event_thread_created(uuid_c, uuid_t, uuid_s,
        thread->title, thread->body);
    return create_thread_second_part(pchannel, session, thread);
}

static enum command_return create_comment_second_part(session_t *session,
    t_messages *pmessages, t_messages *thread
)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;

    if (pmessages->replies)
        ret_val = node_append_data(pmessages->replies, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (pmessages->replies = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    char t_uuid[37], s_uuid[37];
    uuid_unparse(((t_user *) session->user_data)->uid, s_uuid);
    uuid_unparse(thread->uid, t_uuid);
    asprintf(&ret, "212 \"%s\" \"%s\" \"%ld\" \"%s\"", t_uuid,
        s_uuid, pmessages->created_at,
        pmessages->body);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    return SUCCESS;
}

static enum command_return create_comment(t_messages *pmessages,
    session_t *session, char *arg
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char uuid_m[37], uuid_s[37];
    if (!thread)
        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = REPLY;
    thread->m_type = M_REPLY;
    thread->title = NULL;
    thread->body = arg;
    thread->destination = pmessages;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_unparse(pmessages->uid, uuid_m);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_reply_created(uuid_m, uuid_s, thread->body);
    return create_comment_second_part(session, pmessages, thread);
}

enum command_return call_create(t_global *global, session_t *session,
    char **args
)
{
    char *first_arg = args[0];
    char *second_arg = args[1]; // todo

    if (!session->current_team) {
        return create_team(global, session, first_arg, second_arg);
    }
    if (!session->current_channel) {
        return create_channel(session->current_team, session, first_arg,
            second_arg);
    }
    if (!session->current_thread) {
        return create_tread(session->current_channel, session, first_arg,
            second_arg);
    } else {
        return create_comment(session->current_thread, session, first_arg);
    }
}

void command_create(t_global *global, session_t *session, char **args
)
{
    (void) args; // todo parse args
    enum command_return return_val = SUCCESS;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    return_val = call_create(global, session, args);
    if (return_val != SUCCESS) {
        send_message(session->socket, "666 \"system error\"", RESPONSE, LIST);
    }
}