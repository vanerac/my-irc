/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** create_cmd
*/

#include "client.h"

void create_team(char **args)
{
    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(args[0])) {
            case 205:
                client_print_team_created(args[0], args[1], args[2]);
                break;
            case 405:
                client_error_already_exist();
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
}

void create_channel(char **args)
{
    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(args[0])) {
            case 206:
                client_print_channel_created(args[0], args[1], args[2]);
                break;
            case 402:
                client_error_unknown_team(args[0]);
                break;
            case 405:
                client_error_already_exist();
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
}

void create_thread(char **args)
{
    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 207:
                client_print_thread_created(args[0], args[1], (time_t)atol(args[2]), args[3], args[4]);
                break;
            case 402:
                client_error_unknown_team(args[0]);
                break;
            case 403:
                client_error_unknown_channel(args[0]);
                break;
            case 405:
                client_error_already_exist();
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
}

void create_reply_to_thread(char **args)
{
    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 208:
                client_print_reply_created(args[0], args[1], (time_t)atol(args[2]), args[3]);
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
}
