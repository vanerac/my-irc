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
    SUCCESS = 0,
    UNKNOWN_TEAM = -1,
    UNKNOWN_CHANNEL = -2,
    UNKNOWN_THREAD = -3,
    UNKNOWN_USER = -4,
    NOT_AUTH = -5,
    DOUBLE_AUTH = -6,
    SYSTEM_ERROR = -7
};

// enum command_e {
//     INVALID,
//     HELP,
//     LOGIN,
//     LOGOUT,
//     USERS,
//     USR,
//     SEND,
//     MESSAGES,
//     SUBSCRIBE,
//     SUBSCRIBED,
//     UNSUBSCRIBE,
//     USE,
//     CREATE,
//     LIST,
//     INFO
// };


enum command_return command_help(t_global *global, session_t *session, char **args);
enum command_return command_login(t_global *global, session_t *session, char **args);
enum command_return command_logout(t_global *global, session_t *session, char **args);
enum command_return command_users(t_global *global, session_t *session, char **args);
enum command_return command_usr(t_global *global, session_t *session, char **args);
enum command_return command_send(t_global *global, session_t *session, char **args);
enum command_return command_messages(t_global *global, session_t *session, char **args);
enum command_return command_subscribe(t_global *global, session_t *session, char **args);
enum command_return command_subscribed(t_global *global, session_t *session, char **args);
enum command_return command_unsubscribe(t_global *global, session_t *session, char **args);
enum command_return command_use(t_global *global, session_t *session, char **args);
enum command_return command_create(t_global *global, session_t *session, char **args);
enum command_return command_list(t_global *global, session_t *session, char **args);
enum command_return command_info(t_global *global, session_t *session, char **args);

enum command_return is_logged(t_global *global, session_t *session, char
    **args);


typedef struct command_s {
    enum command_e command_id;
    char **args;
    enum command_return (*fn)(t_global *global, session_t *session, char **);
    enum command_return (*check_fn)(t_global *global, session_t *session, char **);
} command_t;

extern const command_t commands_list[];

#endif //C_COMMANDS_H
