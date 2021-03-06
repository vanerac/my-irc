/*
** EPITECH PROJECT, 2021
** C
** File description:
** command_use.c file
*/

#include "commands.h"

bool find_by_uuid(void *it, void *data)
{
    uuid tmp;
    uuid_parse(data, tmp);
    switch (*((enum data_type *) it)) {
    case USER:
        return !uuid_compare(((t_user *) it)->uid, tmp);
    case TEAM:
        return !uuid_compare(((t_teams *) it)->uid, tmp);
    case CHANNEL:
        return !uuid_compare(((t_channel *) it)->uid, tmp);
    case THREAD:
        return !uuid_compare(((t_messages *) it)->uid, tmp);
    case REPLY:
        return !uuid_compare(((t_messages *) it)->uid, tmp);
    case MESSAGE:
        return !uuid_compare(((t_messages *) it)->uid, tmp);
    case SESSION:
        return ((session_t *) it)->user_data &&
            !uuid_compare(((session_t *) it)->user_data->uid, tmp);
    default:
        return false;
    }
}

static enum command_return set_team(t_global *global, session_t *session,
    char *target_uuid
)
{
    list_t *tmp = node_find_fn(global->teams, find_by_uuid, target_uuid);
    if (!tmp) {
        session->error = ERROR_TEAM;
        session->fail_uid = target_uuid;
        return UNKNOWN_TEAM;
    }
    session->current_team = (t_teams *) tmp->data;
    session->current_channel = NULL;
    session->current_thread = NULL;
    return SUCCESS;
}

static enum command_return set_channel(t_global *global, session_t *session,
    char *target_uuid
)
{
    (void) global;
    list_t *channel = NULL;

    if (!session->current_team)
        return UNKNOWN_TEAM;
    channel = node_find_fn(session->current_team->channels,
        find_by_uuid, target_uuid);
    if (!channel) {
        session->error = ERROR_CHANNEL;
        session->fail_uid = target_uuid;
        return UNKNOWN_CHANNEL;
    }
    session->current_channel = (t_channel *) channel->data;
    session->current_thread = NULL;
    return SUCCESS;
}

static enum command_return set_thread(t_global *global, session_t *session,
    char *target_uuid
)
{
    (void) global;
    list_t *thread = NULL;

    if (!session->current_team)
        return UNKNOWN_TEAM;
    if (!session->current_channel)
        return UNKNOWN_CHANNEL;
    thread = node_find_fn(session->current_channel->messages,
        find_by_uuid, target_uuid);
    if (!thread) {
        session->error = ERROR_THREAD;
        session->fail_uid = target_uuid;
        return UNKNOWN_THREAD;
    }
    session->current_thread = (t_messages *) thread->data;
    return SUCCESS;
}

void command_use(t_global *global, session_t *session, char **args
)
{
    enum command_return (*fn[4])(t_global *, session_t *, char *
    ) = {&set_team, &set_channel, &set_thread, NULL};
    enum command_return status = SUCCESS;

    session->current_team = NULL;
    session->current_channel = NULL;
    session->current_thread = NULL;
    for (int i = 0; fn[i] && args[i] && status == SUCCESS; ++i)
        status = fn[i](global, session, args[i]);
    if (status == SUCCESS)
        session->error = NO_ERROR;
}