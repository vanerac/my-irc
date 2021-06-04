/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_third
*/

#include "client.h"

void unsubscribe(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                client_print_unsubscribed(args[0], args[1]);
                break;
            case 402:
                    client_error_unknown_team(args[0]);
                break;
            case 400:
                    client_error_unauthorized();
                break;
        }
    }
    free_table(args);
}

void create(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 205:
                client_event_team_created(args[0], args[1], args[2]);
                break;
            case 206:
                client_print_team_created(args[0], args[1], args[2]);
                break;
            case 207:
                client_event_channel_created(args[0], args[1], args[2]);
                break;   
        }
    }
    create_bis(code, args);
    create_error_response(code, args);
    free_table(args);
}

void create_bis(char *code, char **args)
{
    switch (atoi(code)) {
        case 208:
            client_print_channel_created(args[0], args[1], args[2]);
            break;
        case 209:
            client_event_thread_created(args[0], args[1],
            (time_t)atol(args[2]), args[3], args[4]);
            break;
        case 210:
            client_print_thread_created(args[0], args[1],
            (time_t)atol(args[2]), args[3], args[4]);
            break;
        case 211:
            client_event_thread_reply_received(args[0],
            args[1], args[2], args[3]);
            break;
        case 212:
            client_print_reply_created(args[0], args[1],
            (time_t)atol(args[2]), args[3]);
            break;
    }
}

void info(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 213:
                client_print_user(args[0], args[1], atoi(args[2]));
                break;
            case 214:
                client_print_team(args[0], args[1], args[2]);
                break;
            case 215:
                client_print_channel(args[0], args[1], args[2]);
                break;
        }
    }
    info_bis(code, args);
    free_table(args);
}

void info_bis(char *code, char **args)
{
    switch (atoi(code)) {
        case 216:
            client_print_thread(args[0], args[1],
            (time_t)atol(args[2]), args[3], args[4]);
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