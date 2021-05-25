/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(struct data *var, void *handle)
{
    printf("Here is the help\n");
    var->buffer_client = var->buffer_client;
}

void login(struct data *var, void *handle)
{
    void (*func)() = dlsym(handle, "client_event_logged_in");

    if (array_size(var->splitted_cmd) >= 2){
        var->login = var->splitted_cmd[1];
        func("test1234", "test");
    } else
        return;
}

void logout(struct data *var, void *handle)
{
    var->login = UNSET;
}

void user(struct data *var, void *handle)
{
    printf("Here is the user\n");
    var->buffer_client = var->buffer_client;
}

void users(struct data *var, void *handle)
{
    printf("Here is the users\n");
    var->buffer_client = var->buffer_client;
}

void send(struct data *var, void *handle)
{
    printf("Here is the send\n");
    var->buffer_client = var->buffer_client;
}

void messages(struct data *var, void *handle)
{
    printf("Here is the messages\n");
    var->buffer_client = var->buffer_client;
}

void subscribe(struct data *var, void *handle)
{
    printf("Here is the subscribe\n");
    var->buffer_client = var->buffer_client;
}

void subscribed(struct data *var, void *handle)
{
    printf("Here is the subscribed\n");
    var->buffer_client = var->buffer_client;
}

void unsubscribe(struct data *var, void *handle)
{
    printf("Here is the unsubscribe\n");
    var->buffer_client = var->buffer_client;
}

void use(struct data *var, void *handle)
{
    printf("Here is the use\n");
    var->buffer_client = var->buffer_client;
}

void create(struct data *var, void *handle)
{
    printf("Here is the create\n");
    var->buffer_client = var->buffer_client;
}

void info(struct data *var, void *handle)
{
    printf("Here is the info\n");
    var->buffer_client = var->buffer_client;
}

void list(struct data *var, void *handle)
{
    printf("Here is the list\n");
    var->buffer_client = var->buffer_client;
}