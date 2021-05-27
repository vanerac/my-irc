/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_fifth
*/

#include "client.h"

void info_team_220(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_team");
}

void info_channel_221(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_channel");
}

void info_thread_222(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_thread");
}

void team_created_only_for_creator_223(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_team_created");
}

void channel_created_only_for_creator_224(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_channel_created");
}