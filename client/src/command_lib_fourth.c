/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_fourth
*/

#include "client.h"

void list(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(args[0])) {
            case 201:
                client_print_teams(args[0], args[1], args[2]);
                break;
            case 202:
                client_team_print_channels(args[0], args[1], args[2]);
                break;
            case 203:
                client_channel_print_threads(args[0], args[1],
                (time_t)atol(args[2]), args[3], args[4]);
                break;
        }
    }
    list_bis(code, args);
    free_table(args);
}

void list_bis(char *code, char **args)
{
    switch (atoi(code)) {
        case 204:
            client_thread_print_replies(args[0], args[1],
            (time_t)atol(args[2]), args[3]);
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
        case 400:
            client_error_unauthorized();
            break;
    }
}

void invalid(char *code, char *allargs)
{
    if (code != NULL && atoi(code) == 220){
        printf("%s\n", allargs);
    } else
        printf("INVALID");
}