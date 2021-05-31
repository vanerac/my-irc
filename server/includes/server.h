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

typedef struct session_s {
    int socket;
    bool logged;
    t_user *user_data;
    t_teams *current_team;
    t_channel *current_channel;
    t_messages *current_thread;
} session_t;

#endif //C_SERVER_H
