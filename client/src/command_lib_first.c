/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void login_ok_200(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_logged_in");
    func("test1234", "test");
}

void logout_ok_201(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_logged_out");
}

void dm_received_202(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_private_message_received");
}

void thread_reply_203(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_thread_reply_received");
}

void event_team_created_204(struct data *var) // Every logged user should receive this event (the creator of the team too)
{
    void (*func)() = dlsym(var->handle, "client_event_team_created");
} 