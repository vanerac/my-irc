/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(char *code, char *allargs, lib_func_client_t *lib_client)
{
    switch (atoi(code)) {
    case 200:
        printf("%s", allargs);
        break;
    case 400:
        // client_error_unauthorized;
        break;
    }
}

void login(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(code)) {
            case 200:
                // lib_client[0].func(args[1], args[2]);
                // client_event_logged_in
                break;
            default:
                printf("Error while logging !\n");
                break;
        }
    }
}

void logout(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                // lib_client[1].func(args[1], args[2]);
                // client_event_logged_out
                break;
            default:
                printf("Error while logout !\n");
                break;
        }
    }
}

void user(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                break;
            case 400:
                // client_error_unauthorized
                break;
            case 401:
                // client_error_unknown_user
                break;
            default:
                printf("Error user !\n");
                break;
        }
    }

}

void users(char *code, char *allargs, lib_func_client_t *lib_client) // Every logged user should receive this event (the creator of the team too)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) > 0){
        switch (atoi(code)) {
            case 200:
                // lib_client[12].func(args[1], args[2], args[3]); // => params a convertir en int
                // client_print_users
                break;
            case 400:
                // client_error_unauthorized
            default:
                printf("Error printing userS !\n");
                break;
        }
    }
} 