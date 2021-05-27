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

enum command_return command_help(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_login(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_logout(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_users(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_usr(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_send(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_messages(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_subscribe(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_subscribed(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_unsubscribe(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_use(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_create(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_list(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}

enum command_return command_info(session_t *session, char **args)
{
    (void) session, (void) args;
    return SUCCESS;
}
