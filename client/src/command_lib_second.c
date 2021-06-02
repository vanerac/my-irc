/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_second
*/

#include "client.h"

void send(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(code)) {
            case 200:
                // lib_client[2].func(args[1], args[2]);
                // client_event_private_message_received
                break;
            case 401:
                // client_error_unknown_user
                break;
            case 400:
                // client_error_unauthorized
                break;
            default:
                printf("Error send !\n");
                break;
        }
    }
}

void messages(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(code)) {
            case 200:
                // lib_client[2].func(args[1], args[2]);
                // client_private_message_print_messages
                break;
            case 401:
                // client_error_unknown_user
                break;
            case 400:
                // client_error_unauthorized
                break;
            default:
                printf("Error messages !\n");
                break;
        }
    }
}

void subscribe(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(code)) {
            case 200:
                // client_print_subscribed
                break;
            case 402:
                // client_error_unknown_team
                break;
            case 400:
                // client_error_unauthorized
                break;
            default:
                printf("Error subscribe !\n");
                break;
        }
    }
}

void subscribed(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        // A mettre au clair

        // if (array_size(args) == 1){
        //     switch (atoi(code)) {
        //         case 202:
        //             // client_print_users
        //             break;
        //         case 402:
        //             // client_error_unknown_team
        //             break;
        //         case 400:
        //             // client_error_unauthorized
        //             break;
        //         default:
        //             printf("Error printing users !\n");
        //             break;
        //     }
        // } else {
        //     switch (atoi(code)) {
        //         case 201:
        //             // client_print_teams
        //             break;
        //         case 400:
        //             // client_error_unauthorized
        //             break;
        //         default:
        //             printf("Error printing users !\n");
        //             break;
        //     }
        // }
    }
}

void unsubscribe(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(code)) {
            case 200:
                // client_print_unsubscribed
                break;
            case 402:
                // client_error_unknown_team
                break;
            case 400:
                // client_error_unauthorized
                break;
            default:
                printf("Error unsubscribe !\n");
                break;
        }
    }

}