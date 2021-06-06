/*
** EPITECH PROJECT, 2021
** create channel
** File description:
** create_channel
*/

#include "server.h"
#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

static void notify_channel_created(session_t *session, t_channel *channel)
{
    char *buff = NULL;
    list_t *subs = session->current_team->subscribers;
    session_t *curr = NULL;
    char uuid[37];

    uuid_unparse(channel->uid, uuid);
    asprintf(&buff, "207 \"%s\" \"%s\" \"%s\"", uuid, channel->name,
        channel->desc);
    for (; subs; subs = subs->next) {
        curr = (session_t *) subs->data;
        if (curr->logged) {
            send_message(curr->socket, buff, RESPONSE, CREATE);
        }
    }
    free(buff);
}

static enum command_return create_channel_second_part(t_teams *team,
    session_t *session, t_channel *channel, char *uuid)
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
    asprintf(&ret, "208 \"%s\" \"%s\" \"%s\"", uuid, channel->name,
        channel->desc);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    notify_channel_created(session, channel);
    return SUCCESS;
}

enum command_return create_channel(t_teams *team, session_t *session,
    char *arg, char *arg1)
{
    t_channel *channel = malloc(sizeof(t_channel));
    char uuid[37];
    char t_uuid[37];

    if (!channel)
        return SYSTEM_ERROR;
    if (node_find_fn(session->current_team, &find_by_name, arg)) {
        send_message(session->socket, "405 already exist", RESPONSE, CREATE);
        return SUCCESS;
    }
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