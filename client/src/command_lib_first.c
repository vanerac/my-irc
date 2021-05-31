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
    // void (*func)() = dlsym(var->handle, "client_event_logged_out");
}

void logout(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_event_private_message_received");
}

void user(char **args, lib_func_client_t *lib_client)
{
    // void (*func)() = dlsym(var->handle, "client_event_thread_reply_received");
}

void users(char **args, lib_func_client_t *lib_client) // Every logged user should receive this event (the creator of the team too)
{
    // void (*func)() = dlsym(var->handle, "client_event_team_created");
} 