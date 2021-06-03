/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include <logging_server.h>
#include "commands.h"
#include "message.h"

enum command_return return_invalid(t_global *global, session_t *session, char **args);

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
    {INFO, NULL, &command_info, {&is_logged, NULL}},
};

enum command_return return_invalid(t_global *global, session_t *session, char **args)
{  
    (void)session;
    (void) global, (void) args;
    send_message(session->socket, "220 Invalid Command", RESPONSE, INVALID);
    return UNKNOWN_COMMAND;
}

enum command_return is_logged(t_global *global, session_t *session, char **args)
{
    (void) global, (void) args;
    printf("checking log status\n");
    return session->logged && session->user_data ? SUCCESS : UNAUTHORISED;
}

void command_help(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;

    char *h = "200 /help -> show help\n/login 'user' -> set the user used by"
    " client\n/logout -> disconnect the client from the server\n"
    "/users -> list of all users that exist\n/user 'user_uuid' -> get"
    " information about a user\n/send 'user_uuid' 'message_body' -> send"
    " a message to a user\n/messages 'user_uuid' -> list all messages with a"
    " user\n/subscribe 'team_uuid' -> subscribe to a team\n/subscribed ?"
    "'team_uuid' -> list all subscribed teams or list all users subscribed"
    " to a team\n/unsubscribe 'team_uuid' -> unsubscribe from a team\n"
    "/use ? 'team_uuid' ?'channel_uuid' ?'thread_uuid' -> use specify a "
    "context team/channel/thread\n/create -> create a team/channel/thread\n"
    "/list -> list existing teams/channels/threads\n/info -> display info"
    " about users/team/channel/thread\n";

    send_message(session->socket, h, RESPONSE, HELP);
//    return SUCCESS;
}


void command_users(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}

void command_usr(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}

void command_messages(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}

void command_subscribe(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}

void command_subscribed(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}

void command_unsubscribe(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}


void command_info(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
//    return SUCCESS;
}
