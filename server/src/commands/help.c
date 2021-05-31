/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include <logging_server.h>
#include "commands.h"

const command_t commands_list[] = {{INVALID, NULL, NULL, NULL},
    {HELP, NULL, &command_help, NULL}, {LOGIN, NULL, &command_login, NULL},
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
    {INFO, NULL, &command_info, &is_logged},};

enum command_return is_logged(t_global *global, session_t *session, char **args)
{
    (void) global, (void) args;
    return session->user_data ? SUCCESS : NOT_AUTH;
}

enum command_return command_help(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
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

enum command_return command_list(t_global *global, session_t *session,
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
