/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_third
*/

#include "client.h"

void use(char *code, char *allargs, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_channel_print_threads");
}

void create(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 203:
                lib_client[4].func(args[1], args[2], args[3], args[4]);
                break;
            case 204:
                lib_client[3].func(args[1], args[2], args[3]);
                break;
            case 205:
                lib_client[8].func(args[1], args[2], args[3]);
                break;
            case 206:
                lib_client[5].func(args[1], args[2], args[3]);
                break;
            default:
                printf("Error thread reply received !\n");
                break;
        }
    }
}

void info(char *code, char *allargs, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_private_message_print_messages");
}

void list(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 208:
                lib_client[11].func(args[1], args[2], args[3]);
                break;
            case 209:
                lib_client[21].func(args[1], args[2], args[3]);
                break;
            case 210:
                lib_client[19].func(args[1], args[2], args[3], args[4], args[5]);
                break;
            case 211:
                lib_client[19].func(args[1], args[2], args[3], args[4], args[5]);
                break;
            default:
                printf("Error while listing !\n");
                break;
        }
    }
}

void invalid(char *code, char *allargs, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_error_unknown_team");
}