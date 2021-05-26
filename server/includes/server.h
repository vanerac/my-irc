/*
** EPITECH PROJECT, 2021
** C
** File description:
** server.h file
*/

#ifndef C_SERVER_H
#define C_SERVER_H

#include "struct.h"

int myteams_server(int server_socket);

typedef struct session_s {
    int socket;
    bool logged;
    t_user *user_data;
    uuid *current_team;
    uuid *current_channel;
    uuid *current_thread;
} session_t;

#endif //C_SERVER_H
