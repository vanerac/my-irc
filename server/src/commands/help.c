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

enum command_return return_invalid(t_global *global, session_t *session,
    char **args
);

const command_t commands_list[] = {
    {INVALID, NULL, NULL, {&return_invalid, NULL}},
    {HELP, NULL, &command_help, {&is_logged, NULL}},
    {LOGIN, NULL, &command_login, {NULL}},
    {LOGOUT, NULL, &command_logout, {&is_logged, NULL}},
    {USERS, NULL, &command_users, {&is_logged, NULL}},
    {USR, NULL, &command_usr, {&is_logged, NULL}},
    {SEND, NULL, &command_send, {&is_logged, NULL}},
    {MESSAGES, NULL, &command_messages, {&is_logged, NULL}},
    {SUBSCRIBE, NULL, &command_subscribe, {&is_logged, NULL}},
    {SUBSCRIBED, NULL, &command_subscribed, {&is_logged, NULL}},
    {UNSUBSCRIBE, NULL, &command_unsubscribe, {&is_logged, NULL}},
    {USE, NULL, &command_use, {&is_logged, NULL}},
    {CREATE, NULL, &command_create, {&is_logged, NULL}},
    {LIST, NULL, &command_list, {&is_logged, NULL}},
    {INFO, NULL, &command_info, {&is_logged, NULL}},};

enum command_return return_invalid(t_global *global, session_t *session,
    char **args
)
{
    (void) session;
    (void) global, (void) args;
    send_message(session->socket, "399 Invalid Command", RESPONSE, INVALID);
    return UNKNOWN_COMMAND;
}

enum command_return is_logged(t_global *global, session_t *session, char **args
)
{
    (void) global, (void) args;

    if (session->logged && session->user_data)
        return SUCCESS;
    send_message(session->socket, "400 client not logged", RESPONSE, INVALID);
    return UNAUTHORISED;
}

void command_help(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;

    char *h = "200 /help -> show help\n/login 'user' -> set the user used by"
              " client\n/logout -> disconnect the client from the server\n"
              "/users -> list of all users that exist\n/user 'user_uuid' -> get"
              " information about a user\n/send 'user_uuid' 'message_body' -> send"
              " a message to a user\n/messages 'user_uuid' -> list all messages with"
              " a user\n/subscribe 'team_uuid' -> subscribe to a team\n/subscribed ?"
              "'team_uuid' -> list all subscribed teams or list all users subscribed"
              " to a team\n/unsubscribe 'team_uuid' -> unsubscribe from a team\n"
              "/use ? 'team_uuid' ?'channel_uuid' ?'thread_uuid' -> use specify a "
              "context team/channel/thread\n/create -> create team/channel/thread\n"
              "/list -> list existing teams/channels/threads\n/info -> display info"
              " about users/team/channel/thread\n";

    send_message(session->socket, h, RESPONSE, HELP);
}

void command_users(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    list_t *all_users = global->all_user;
    t_user *cur = NULL;
    char uuid[37];

    for (; all_users; all_users = all_users->next) {
        cur = (t_user *) all_users->data;
        if (!cur)
            continue;
        uuid_unparse(cur->uid, uuid);
        SEND_MESSAGE(session->socket, RESPONSE, USERS,
            "200 \"%s\" \"%s\" \"%d\"\n", uuid, cur->username,
            (cur->logged) ? 1 : 0)
    }
}

void command_usr(t_global *global, session_t *session, char **args)
{
    char *buffer;
    char uuid[37];

    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    list_t *node = node_find_fn(global->sessions, find_by_uuid, args[0]);
    if (!node) {
        asprintf(&buffer, "401 \"%s\"", args[0]);
        send_message(session->socket, buffer, RESPONSE, USR);
        return;
    }
    session_t *user = (session_t *) node->data;

    uuid_unparse(((t_user *) user->user_data)->uid, uuid);
    asprintf(&buffer, "200 \"%s\" \"%s\" \"%i\"", uuid,
        ((t_user *) user->user_data)->username, user->logged ? 1 : 0);
    send_message(session->socket, buffer, RESPONSE, USR);
    free(buffer);
}

void command_messages(t_global *global, session_t *session, char **args)
{
    uuid target;
    uuid *uuids[2] = {&session->user_data->uid, &target};
    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);

    CHECK_ARGS(args, 1, session->socket)
    uuid_parse(args[0], target);
    if (!dms) {
        SEND_MESSAGE(session->socket, RESPONSE, MESSAGES, "401 \"%s\"",
            args[0]);
        return;
    }
    t_dm *dm = dms->data;
    for (list_t *i = dm->messages; i; i = i->next) {
        t_messages *m = i->data;
        char id[37];
        uuid_unparse(m->author->uid, id);
        SEND_MESSAGE(session->socket, RESPONSE, MESSAGES,
            "200 \"%s\" \"%lud\" \"%s\"\n", id, m->created_at, m->body)
    }
}

void command_subscribe(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    char *buffer = NULL;
    enum command_return ret_val = SUCCESS;

    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    list_t *node = node_find_fn(global->teams, find_by_uuid, args[0]);

    char user_uuid[37];
    char team_uuid[37];
    if (!node) {
        asprintf(&buffer, "402 \"%s\"", args[0]);
        send_message(session->socket, buffer, RESPONSE, SUBSCRIBE);
        return;
    }
    t_teams *team = node->data;
    if (team->subscribers)
        ret_val = node_append_data(team->subscribers, session) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (team->subscribers = (node_list_create(session))) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS) {
        send_message(session->socket, "666 \"system error\"", RESPONSE,
            INVALID);
        return;
    }
    uuid_unparse(team->uid, team_uuid);
    uuid_unparse(session->user_data->uid, user_uuid);
    server_event_user_subscribed(team_uuid, user_uuid);
    asprintf(&buffer, "200 \"%s\" \"%s\"", user_uuid, team_uuid);
    send_message(session->socket, buffer, RESPONSE, SUBSCRIBE);
    free(buffer);
}

enum command_return display_subscribed_teams(t_global *global,
    session_t *session
)
{
    list_t *all_teams = global->teams;
    t_teams *team = NULL;
    char uuid[37];
    char user_uuid[37];

    uuid_unparse(session->user_data->uid, user_uuid);
    for (; all_teams; all_teams = all_teams->next) {
        team = all_teams->data;
        uuid_unparse(team->uid, uuid);
        if (node_find_fn(team->subscribers, &find_by_uuid, user_uuid)) {
            SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBE,
                "201 \"%s\" \"%s\" \"%s\"\n", uuid, team->name, team->desc);
        }
    }

    return SUCCESS;
}

enum command_return display_subscribers_to_team(t_global *global,
    session_t *session, char *uid
)
{
    list_t *node = node_find_fn(global->teams, find_by_uuid, uid);
    t_teams *team = NULL;
    session_t *user = NULL;
    char uuid[37];

    if (!node) {
        SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBE, "402 \"%s\"", uuid);
        return SUCCESS;
    }
    team = node->data;
    for (list_t *i = team->subscribers; i; i = i->next) {
        user = (session_t *) i->data;
        if (!session->user_data)
            continue;
        uuid_unparse(user->user_data->uid, uuid);
        SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBED,
            "202 \"%s\" \"%s\" \"%d\"\n", uuid, user->user_data->username,
            user->logged);
    }
    return SUCCESS;
}

void command_subscribed(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    enum command_return ret_val = SUCCESS;

    if (args || !args[0]) {
        ret_val = display_subscribed_teams(global, session);
    } else {
        ret_val = display_subscribers_to_team(global, session, args[0]);
    }
    if (ret_val != SUCCESS)
        send_message(session->socket, "666 \"system error\"", RESPONSE,
            INVALID);
}

void command_unsubscribe(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;

    CHECK_ARGS(args, 1, session->socket);
    list_t *node = node_find_fn(global->teams, &find_by_uuid, args[0]);
    if (!node) {
        SEND_MESSAGE(session->socket, RESPONSE, UNSUBSCRIBE, "400 \"%s\"\n",
            args[0])
        return;
    }
    t_teams *team = node->data;
    team->subscribers = node_delete_fn(team->subscribers, &find_by_uuid,
        args[0]);
    char user_uuid[37];
    uuid_unparse(session->user_data->uid, user_uuid);
    SEND_MESSAGE(session->socket, RESPONSE, UNSUBSCRIBE, "200 \"%s\" \"%s\"\n",
        user_uuid, args[0])
}
