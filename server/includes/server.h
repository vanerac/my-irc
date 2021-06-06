/*
** EPITECH PROJECT, 2021
** C
** File description:
** server.h file
*/

#ifndef C_SERVER_H
#define C_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

int myteams_server(int server_socket);
char **str_to_word_array(char *str, char spliter_char);
char **split_by_quote(char *str);

enum error_use {
    NO_ERROR,
    ERROR_TEAM,
    ERROR_CHANNEL,
    ERROR_THREAD
};

typedef struct session_s {
    enum data_type type;
    int socket;
    bool logged;
    char *fail_uid;
    enum error_use error;
    t_user *user_data;
    t_teams *current_team;
    t_channel *current_channel;
    t_messages *current_thread;
} session_t;

void send_error_to_client(session_t *session);
bool args_len(char **args, int len);

#define CHECK_ARGS(args, len, socket) \
    if (!args_len(args, len))        \
        return (void) send_message(socket, "665 invalid args",RESPONSE, \
        INVALID);

#endif //C_SERVER_H
