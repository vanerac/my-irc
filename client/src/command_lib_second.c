/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_second
*/

#include "client.h"

void send(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0) {
        switch (atoi(code)) {
            case 200:
                client_event_private_message_received(args[0], args[1]);
                break;
            case 401:
                client_error_unknown_user(args[0]);
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
    free_table(args);
}

void messages(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0) {
        switch (atoi(code)) {
            case 200:
                client_private_message_print_messages(args[0],
                (time_t)atol(args[1]), args[2]);
                break;
            case 401:
                client_error_unknown_user(args[0]);
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
    free_table(args);
}

void subscribe(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0) {
        switch (atoi(code)) {
            case 200:
                client_print_subscribed(args[0], args[1]);
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

void subscribed(char *code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    if (array_size(args) > 0) {
        switch (atoi(code)) {
            case 202:
                client_print_users(args[0], args[1], atoi(args[2]));
                break;
            case 402:
                client_error_unknown_team(args[0]);
                break;
            case 400:
                client_error_unauthorized();
                break;
            }
    }
    subscribed_bis(code, args);
    free_table(args);
}

void subscribed_bis(char *code, char **args)
{
    switch (atoi(code)) {
        case 201:
            client_print_teams(args[0], args[1], args[2]);
            break;
        case 400:
            client_error_unauthorized();
            break;
    }
}