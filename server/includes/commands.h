/*
** EPITECH PROJECT, 2021
** C
** File description:
** commands_list.h file
*/

#ifndef C_COMMANDS_H
#define C_COMMANDS_H

#include "server.h"
#include "command_enum.h"

enum command_return {
    SUCCESS = 200,
    UNAUTHORISED = 400,
    UNKNOWN_USER = 401,
    UNKNOWN_TEAM = 402,
    UNKNOWN_CHANNEL = 403,
    UNKNOWN_THREAD = 404,
    ALREADY_EXISTS =  405,
    SYSTEM_ERROR = 500,
    FATAL_ERROR = 666,
    DOUBLE_AUTH = -6,
};

void command_help(t_global *global, session_t *session,
    char **args);
void command_login(t_global *global, session_t *session,
    char **args);
void command_logout(t_global *global, session_t *session,
    char **args);
void command_users(t_global *global, session_t *session,
    char **args);
void command_usr(t_global *global, session_t *session,
    char **args);
void command_send(t_global *global, session_t *session,
    char **args);
void command_messages(t_global *global, session_t *session,
    char **args);
void command_subscribe(t_global *global, session_t *session,
    char **args);
void command_subscribed(t_global *global, session_t *session,
    char **args);
void command_unsubscribe(t_global *global, session_t *session,
    char **args);
void command_use(t_global *global, session_t *session,
    char **args);
void command_create(t_global *global, session_t *session,
    char **args);
void command_list(t_global *global, session_t *session,
    char **args);
void command_info(t_global *global, session_t *session,
    char **args);

enum command_return is_logged(t_global *global, session_t *session,
char **args);

typedef enum command_return (*command_ptr)(t_global *,session_t *, char **);

typedef struct command_s {
    enum command_e command_id;
    char **args;
    void (*fn)(t_global *, session_t *,char **);
    command_ptr check_fn[3];
} command_t;

extern const command_t commands_list[];

#endif //C_COMMANDS_H