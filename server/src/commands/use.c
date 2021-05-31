/*
** EPITECH PROJECT, 2021
** C
** File description:
** command_use.c file
*/

#include "commands.h"

list_t *l;

static bool find_by_uuid(void *it, void *data)
{
    switch (*((enum data_type *) it)) {
    case UNKNOWN:
        return false;
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

enum command_return command_use(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    (void) find_by_uuid;

//    enum order {
//        team,
//        channel,
//        thread
//    };
//    list_t *prev = (void *) 1;
//
//    for (enum order i = team; args[i] && i <= thread; ++i) {
//        list_t *buffer = NULL;
//        // todo error management
//        switch (i) {
//        case team: {
//            buffer = node_find_fn(global->teams, find_by_uuid, args[i]);
//            session->current_team = buffer ? ((t_teams *) buffer->data) : NULL;
//            prev = buffer;
//        }
//            break;
//        case channel: {
//            buffer = node_find_fn(prev, find_by_uuid, args[i]);
//            session->current_channel =
//                buffer && prev ? ((t_channel *) buffer->data) : NULL;
//            prev = buffer;
//        }
//            break;
//        case thread: {
//            buffer = node_find_fn(prev, find_by_uuid, args[i]);
//            session->current_thread =
//                buffer && prev ? ((t_messages *) buffer->data) : NULL;
//            prev = buffer;
//        }
//            break;
//        }
//    }

    return SUCCESS;
}