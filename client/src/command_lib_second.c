/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_second
*/

#include "client.h"

void event_channel_created_205(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_channel_created");
}

void event_thread_created_206(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_thread_created");
}

void print_users_207(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_users");
}

void print_teams_208(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_teams");
}

void print_channels_209(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_team_print_channels");
}