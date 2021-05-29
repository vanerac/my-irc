/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_second
*/

#include "client.h"

void send(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_channel_created");
}

void messages(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_thread_created");
}

void subscribe(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_users");
}

void subscribed(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_teams");
}

void unsubscribe(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_team_print_channels");
}