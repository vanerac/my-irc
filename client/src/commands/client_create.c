/*
** EPITECH PROJECT, 2021
** client create
** File description:
** client_create
*/

#include "client.h"

void create_error_response(int code, char **args)
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
        case 405:
            client_error_already_exist();
            break;
    }
}

void create_third(int code, char **args)
{
    switch (code) {
        case 210:
            if (get_array_size(args) >= 5)
                client_print_thread_created(args[0], args[1],
                (time_t)atol(args[2]), args[3], args[4]);
            break;
        case 211:
            if (get_array_size(args) >= 4)
                client_event_thread_reply_received(args[0],
                args[1], args[2], args[3]);
            break;
        case 212:
            if (get_array_size(args) >= 4)
                client_print_reply_created(args[0], args[1],
                (time_t)atol(args[2]), args[3]);
            break;
    }
}

void create_second(int code, char **args)
{
    switch (code) {
        case 207:
            if (get_array_size(args) >= 3)
                client_event_channel_created(args[0], args[1], args[2]);
            break;
        case 208:
            if (get_array_size(args) >= 3)
                client_print_channel_created(args[0], args[1], args[2]);
            break;
        case 209:
            if (get_array_size(args) >= 5)
                client_event_thread_created(args[0], args[1],
                (time_t)atol(args[2]), args[3], args[4]);
            break;
    }
}

void create(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 205:
            if (get_array_size(args) >= 3)
                client_event_team_created(args[0], args[1], args[2]);
            break;
        case 206:
            if (get_array_size(args) >= 3)
                client_print_team_created(args[0], args[1], args[2]);
            break;
    }
    create_second(code, args);    
    create_third(code, args);
    create_error_response(code, args);
    free_table(args);
}