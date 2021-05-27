/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_sixth
*/

#include "client.h"

void thread_created_only_for_creator_225(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_thread_created");
}

void reply_created_only_for_creator_226(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_reply_created");
}

void subscribed_created_only_for_creator_227(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_subscribed");
}

void unsubscribed_created_only_for_creator_228(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_unsubscribed");
}