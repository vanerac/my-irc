/*
** EPITECH PROJECT, 2021
** client list
** File description:
** client_list
*/

#include "client.h"

void list_error_response(int code, char **args)
{
    switch (code) {
        case 402:
            if (get_array_size(args) >= 1)
                client_error_unknown_team(args[0]);
            break;
        case 403:
            if (get_array_size(args) >= 1)
                client_error_unknown_channel(args[0]);
            break;
        case 404:
            if (get_array_size(args) >= 1)
                client_error_unknown_thread(args[0]);
            break;
    }
}

void list_second(int code, char **args)
{
    switch (code) {
        case 203:
            if (get_array_size(args) >= 5)
                client_channel_print_threads(args[0], args[1],
                (time_t)atol(args[2]), args[3], args[4]);
            break;
        case 204:
            if (get_array_size(args) >= 4)
                client_thread_print_replies(args[0], args[1],
                (time_t)atol(args[2]), args[3]);
            break;
    }
}

void list(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 201:
            if (get_array_size(args) >= 3)
                client_print_teams(args[0], args[1], args[2]);
            break;
        case 202:
            if (get_array_size(args) >= 3)
                client_team_print_channels(args[0], args[1], args[2]);
            break;
    }
    list_second(code, args);
    list_error_response(code, args);
    free_table(args);
}