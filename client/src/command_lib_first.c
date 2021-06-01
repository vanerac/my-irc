/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(char *code, char *allargs, lib_func_client_t *lib_client)
{
    if (strcmp(code, "200") == 0)
        printf("%s", allargs);
    // void (*func)() = dlsym(var->handle, "client_event_logged_in");
    // func("test1234", "test");
}

void login(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 200:
                lib_client[0].func(args[1], args[2]);
                break;
            default:
                printf("Error while logging in !\n");
                break;
        }
    }
}

void logout(char *code, char *allargs, lib_func_client_t *lib_client)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 3){
        switch (atoi(args[0])) {
            case 201:
                lib_client[1].func(args[1], args[2]);
                break;
            default:
                printf("Error while logout !\n");
                break;
        }
    }
}

void user(char *code, char *allargs, lib_func_client_t *lib_client)
{
}

void users(char *code, char *allargs, lib_func_client_t *lib_client) // Every logged user should receive this event (the creator of the team too)
{
    char **args = str_to_word_array(allargs, ' ');

    if (!args)
        return;
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 207:
                lib_client[12].func(args[1], args[2], args[3]); // => params a convertir en int
                break;
            default:
                printf("Error printing users !\n");
                break;
        }
    }
} 