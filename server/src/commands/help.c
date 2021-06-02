/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include <logging_server.h>
#include "commands.h"
#include "message.h"

const command_t commands_list[] = {
    {INVALID, NULL, NULL, NULL},
    {HELP, NULL, &command_help, &is_logged},
    {LOGIN, NULL, &command_login, NULL},
    {LOGOUT, NULL, &command_logout, &is_logged},
    {USERS, NULL, &command_users, &is_logged},
    {USR, NULL, &command_usr, &is_logged},
    {SEND, NULL, &command_send, &is_logged},
    {MESSAGES, NULL, &command_messages, &is_logged},
    {SUBSCRIBE, NULL, &command_subscribe, &is_logged},
    {SUBSCRIBED, NULL, &command_subscribed, &is_logged},
    {UNSUBSCRIBE, NULL, &command_unsubscribe, &is_logged},
    {USE, NULL, &command_use, &is_logged},
    {CREATE, NULL, &command_create, &is_logged},
    {LIST, NULL, &command_list, &is_logged},
    {INFO, NULL, &command_info, &is_logged},
};

enum command_return is_logged(t_global *global, session_t *session, char **args)
{
    (void) global, (void) args;
    printf("checking log status\n");
    return session->user_data ? SUCCESS : NOT_AUTH;
}

enum command_return command_help(t_global *global, session_t *session,
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
    return SUCCESS;
}


enum command_return command_users(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_usr(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_send(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_messages(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_subscribe(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_subscribed(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_unsubscribe(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}


enum command_return command_info(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}
