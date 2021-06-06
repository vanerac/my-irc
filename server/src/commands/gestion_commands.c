/*
** EPITECH PROJECT, 2021
** C
** File description:
** help.c file
*/

#include "logging_server.h"
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
    {INFO, NULL, &command_info, {&is_logged, NULL}},
};

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