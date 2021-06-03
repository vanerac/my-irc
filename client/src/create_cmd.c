/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** create_cmd
*/

#include "client.h"

void create_error_response(char *code, char **args)
{
    switch (atoi(code)) {
        case 400:
            client_error_unauthorized();
            break;
        case 402:
            client_error_unknown_team(args[0]);
            break;
        case 403:
            client_error_unknown_channel(args[0]);
            break;
        case 404:
            client_error_unknown_thread(args[0]);
            break;
        case 405:
            client_error_already_exist();
            break;
    }
}