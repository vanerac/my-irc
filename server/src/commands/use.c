/*
** EPITECH PROJECT, 2021
** C
** File description:
** command_use.c file
*/

#include "commands.h"

static bool find_by_uuid(void *it, void *data)
{
    switch (*((enum data_type *) it)) {
    case USER:
        return !uuid_compare(((t_user *) it)->uid, ((t_user *) data)->uid);
    case TEAM:
        return !uuid_compare(((t_teams *) it)->uid, ((t_teams *) data)->uid);
    case CHANNEL:
        return !uuid_compare(((t_channel *) it)->uid,
            ((t_channel *) data)->uid);
    case THREAD:
        return !uuid_compare(((t_messages *) it)->uid,
            ((t_messages *) data)->uid);
    case REPLY:
        return !uuid_compare(((t_messages *) it)->uid,
            ((t_messages *) data)->uid);
    case MESSAGE:
        return !uuid_compare(((t_messages *) it)->uid,
            ((t_messages *) data)->uid);
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
    if (!session->current_team)
        return UNKNOWN_TEAM;
    list_t *channel = node_find_fn(session->current_team->channels,
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
    if (!session->current_team)
        return UNKNOWN_TEAM;
    if (!session->current_channel)
        return UNKNOWN_CHANNEL;
    list_t *thread = node_find_fn(session->current_channel->messages,
        find_by_uuid, target_uuid);
    if (!thread) {
        session->error = ERROR_THREAD;
        session->fail_uid = target_uuid;
        return UNKNOWN_THREAD;
    }
    session->current_thread = (t_messages *) thread->data;
    return SUCCESS;
}

void command_use(t_global *global, session_t *session,
    char **args
)
{
    enum command_return (*fn[4])(t_global *, session_t *, char *
    ) = {&set_team, &set_channel, &set_thread, NULL};

    enum command_return status = SUCCESS;
    for (int i = 0; fn[i] && args[i] && status == SUCCESS; ++i)
        status = fn[i](global, session, args[i]);
    if (status == SUCCESS)
        session->error = NO_ERROR;
//    return status;
}