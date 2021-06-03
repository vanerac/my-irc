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

// todo handle duplicates

static void create_team(t_global *global, char *name, char *desc
)
{
    t_teams *team = malloc(sizeof(t_teams));
    char uuid[37];
    //    if (!team)
    //        return SYSTEM_ERROR;
    uuid_generate(team->uid);
    team->name = strdup(name);
    team->desc = strdup(desc);
    team->channels = NULL;
    team->type = TEAM;
    team->users = NULL;
    uuid_unparse(team->uid, uuid);
    server_event_team_created(uuid, name, desc);
    if (global->teams)
        node_append_data(global->teams, team);
    else
        (global->teams = node_list_create(team));
}

static void create_channel(t_teams *team, char *arg, char *arg1)
{
    t_channel *channel = malloc(sizeof(t_channel));
    char uuid[37];
    //    if (!channel)
    //        return SYSTEM_ERROR;
    channel->type = CHANNEL;
    channel->name = arg;
    channel->desc = arg1;
    uuid_generate(channel->uid);
    uuid_unparse(channel->uid, uuid);
    channel->messages = NULL;
    server_event_channel_created((char const *) team->uid, uuid,
        channel->name);
    if (team->channels)
        node_append_data(team->channels, channel);
    else
        (team->channels = node_list_create(channel));
}

static void create_tread(t_channel *pChannel, session_t *session, char *arg,
    char *arg1
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char uuid_t[37], uuid_s[37];
    //    if (!thread)
    //        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = THREAD;
    thread->m_type = M_THREAD;
    thread->body = arg1;
    thread->title = arg;
    thread->destination = pChannel;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_unparse(thread->uid, uuid_t);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_thread_created((char const *) pChannel->uid, uuid_t, uuid_s,
        thread->title, thread->body);
    if (pChannel->messages)
        node_append_data(pChannel->messages, thread);
    else
        (pChannel->messages = node_list_create(thread));
}

static void create_comment(t_messages *pMessages, session_t *session, char *arg
)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char uuid_m[37], uuid_s[37];
    //    if (!thread)
    //        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = REPLY;
    thread->m_type = M_REPLY;
    thread->title = NULL;
    thread->body = arg;
    thread->destination = pMessages;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_unparse(pMessages->uid, uuid_m);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_thread_new_reply(uuid_m, uuid_s, thread->body);
    if (pMessages->replies)
        node_append_data(pMessages->replies, thread);
    else
        (pMessages->replies = node_list_create(thread));
}

void command_create(t_global *global, session_t *session,
    char **args
)
{
    (void) args, (void) global, (void) session; // todo parse args
    (void) create_channel, (void) create_comment, (void) create_team, (void)
    create_tread;
//    char *first_arg = args[0], *second_arg = args[1]; // todo
//    if (!session->current_team) {
//        return create_team(global, first_arg, second_arg);;
//    } else if (!session->current_channel) {
//        return create_channel(session->current_team, first_arg, second_arg);
//    }
//    if (!session->current_thread) {
//        return create_tread(session->current_channel, session, first_arg,
//            second_arg);
//    } else {
//        return create_comment(session->current_thread, session, first_arg);
//    }

}