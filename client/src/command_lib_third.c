/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_third
*/

#include "client.h"

void use(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_channel_print_threads");
}

void create(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_thread_print_replies");
}

void info(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_private_message_print_messages");
}

void list(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unknown_team");
}