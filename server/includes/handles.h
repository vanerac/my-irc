/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** handles.h file
*/

#ifndef B_NWP_400_BDX_4_1_MYTEAMS_CORENTIN_MAS_HANDLES_H
#define B_NWP_400_BDX_4_1_MYTEAMS_CORENTIN_MAS_HANDLES_H

#include "list.h"
#include "server.h"

int handle_command(t_global *global, session_t *session);

void handle_connections(list_t *sessions, int server_socket);

#endif //B_NWP_400_BDX_4_1_MYTEAMS_CORENTIN_MAS_HANDLES_H
