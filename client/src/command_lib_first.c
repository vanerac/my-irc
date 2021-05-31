/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_logged_in");
    func("test1234", "test");
}

void login(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_logged_out");
}

void logout(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_private_message_received");
}

void user(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_thread_reply_received");
}

void users(struct data *var) // Every logged user should receive this event (the creator of the team too)
{
    void (*func)() = dlsym(var->handle, "client_event_team_created");
} 