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
    UNKNOWN_USER = -3,
    NOT_AUTH = -4,
    DOUBLE_AUTH = -5,
    SYSTEM_ERROR = -6
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

enum command_return command_help(session_t *session, char **args);
enum command_return command_login(session_t *session, char **args);
enum command_return command_logout(session_t *session, char **args);
enum command_return command_users(session_t *session, char **args);
enum command_return command_usr(session_t *session, char **args);
enum command_return command_send(session_t *session, char **args);
enum command_return command_messages(session_t *session, char **args);
enum command_return command_subscribe(session_t *session, char **args);
enum command_return command_subscribed(session_t *session, char **args);
enum command_return command_unsubscribe(session_t *session, char **args);
enum command_return command_use(session_t *session, char **args);
enum command_return command_create(session_t *session, char **args);
enum command_return command_list(session_t *session, char **args);
enum command_return command_info(session_t *session, char **args);

typedef struct command_s {
    enum command_e command_id;
    char **args;
    int (*fn)(session_t *session, char **);
} command_t;

extern const command_t commands_list[];

#endif //C_COMMANDS_H
