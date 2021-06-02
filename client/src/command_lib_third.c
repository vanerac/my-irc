/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_third
*/

#include "client.h"

void create(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 205:
                create_team(args);
                break;
            case 206:
                create_channel(args);
                break;
            case 207:
                create_thread(args);
                break;
            case 208:
                create_reply_to_thread(args);
                break;
            default:
                printf("Error create !\n");
                break;
        }
    }
}

void info(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 205:
                client_print_user(args[0], args[1], atoi(args[2]));
                break;
            case 206:
                client_print_team(args[0], args[1], args[2]);
                break;
            case 207:
                client_print_channel(args[0], args[1], args[2]);
                break;
            case 208:
                client_print_thread(args[0], args[1], args[2], args[3], args[4]);
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
            default:
                printf("Error Info !\n");
                break;
        }
    }
}

void list(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

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
                client_channel_print_threads(args[0], args[1], args[2], args[3], args[4]);
                break;
            case 204:
                client_thread_print_replies(args[0], args[1], args[2], args[3]);
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
            default:
                printf("Error while listing !\n");
                break;
        }
    }
}

void invalid(char *code, char *allargs)
{
    switch (atoi(code)) {
    case 220:
        printf("%s\n", allargs);
        break;
    default:
        printf("Invalid Command !\n");
        break;
    }
}