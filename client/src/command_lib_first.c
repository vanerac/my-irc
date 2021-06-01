/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_event_logged_in");
    // func("test1234", "test");
}

void login(char **args, lib_func_client_t *lib_client)
{
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

void logout(char **args, lib_func_client_t *lib_client)
{
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

void user(char **args, lib_func_client_t *lib_client)
{
}

void users(char **args, lib_func_client_t *lib_client) // Every logged user should receive this event (the creator of the team too)
{
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