/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib_fourth
*/

#include "client.h"

void unknown_thread_215(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unknown_thread");
}

void unknown_user_216(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unknown_user");
}

void no_auth_217(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_unauthorized");
}

void already_exist_218(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_error_already_exist");
}

void info_user_219(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_print_user");
}