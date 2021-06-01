/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_second
*/

#include "client.h"

void send(char **args, lib_func_client_t *lib_client)
{
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 202:
                lib_client[2].func(args[1], args[2]);
                break;
            default:
                printf("Error DM received !\n");
                break;
        }
    }
}

void messages(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_event_thread_created");
}

void subscribe(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_print_users");
}

void subscribed(char **args, lib_func_client_t *lib_client)
{
    if (array_size(args) < 0){
        switch (atoi(args[0])) {
            case 207:
                lib_client[12].func(args[1], args[2], args[3]); // => params a convertir en int
                break;
            case 208:
                lib_client[11].func(args[1], args[2], args[3]);
                break;
            default:
                printf("Error printing users !\n");
                break;
        }
    }
}

void unsubscribe(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_team_print_channels");
}