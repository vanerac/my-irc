/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(char *code, char *allargs)
{
    switch (atoi(code)) {
    case 200:
        printf("%s", allargs);
        break;
    case 400:
        client_error_unauthorized();
        break;
    }
}

void login(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                client_event_logged_in(args[0], args[1]);
                break;
        }
    }
    free(args);
}

void logout(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                client_event_logged_out(args[0], args[1]);
                exit(0);
                break;
        }
    }
    free(args);
}

void user(char *code, char *allargs)
{
    switch (atoi(code)) {
        case 200:
            break;
        case 400:
            client_error_unauthorized();
            break;
        case 401:
            client_error_unknown_user(allargs);
            break;
    }
}

void users(char *code, char *allargs)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                client_print_users(args[0], args[1], atoi(args[2]));
                break;
            case 400:
                client_error_unauthorized();
                break;
        }
    }
    free(args);
}