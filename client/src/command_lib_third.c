/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_third
*/

#include "client.h"

void print_threads_210(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_channel_print_threads");
}

void print_replies_211(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_thread_print_replies");
}

void print_dm_212(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_private_message_print_messages");
}

void unknown_team_213(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unknown_team");
}

void unknown_channel_214(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unknown_channel");
}