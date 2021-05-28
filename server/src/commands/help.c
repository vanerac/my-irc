/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include "commands.h"
const command_t commands_list[] = {
    {INVALID, NULL, NULL},
    {HELP, NULL, &command_help},
    {LOGIN, NULL, &command_login},
    {LOGOUT, NULL, &command_logout},
    {USERS, NULL, &command_users},
    {USR, NULL, &command_usr},
    {SEND, NULL, &command_send},
    {MESSAGES, NULL, &command_messages},
    {SUBSCRIBE, NULL, &command_subscribe},
    {SUBSCRIBED, NULL, &command_subscribed},
    {UNSUBSCRIBE, NULL, &command_unsubscribe},
    {USE, NULL, &command_use},
    {CREATE, NULL, &command_create},
    {LIST, NULL, &command_list},
    {INFO, NULL, &command_info},
};

enum command_return command_help(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_login(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    // is user already logged in ?
    //
    return SUCCESS;
}

enum command_return command_logout(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_users(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_usr(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_send(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_messages(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_subscribe(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_subscribed(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_unsubscribe(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}





enum command_return command_list(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}

enum command_return command_info(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    return SUCCESS;
}
