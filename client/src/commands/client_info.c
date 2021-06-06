/*
** EPITECH PROJECT, 2021
** client info
** File description:
** client_info
*/
#include "client.h"

void info_error_response(int code, char **args)
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

void info_second(int code, char **args)
{
    switch (code) {
        case 215:
            if (get_array_size(args) >= 3)
                client_print_channel(args[0], args[1], args[2]);
            break;
        case 216:
            if (get_array_size(args) >= 5)
                client_print_thread(args[0], args[1],
                (time_t)atol(args[2]), args[3], args[4]);
            break;
    }
}

void info(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 213:
            if (get_array_size(args) >= 3)
                client_print_user(args[0], args[1], atoi(args[2]));
            break;
        case 214:
            if (get_array_size(args) >= 3)
                client_print_team(args[0], args[1], args[2]);
            break;
    }
    info_second(code, args);
    info_error_response(code, args);
    free_table(args);
}