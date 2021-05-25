/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** command_lib
*/

#include "client.h"

void help(struct data *var)
{
    printf("Here is the help\n");
}

void login(struct data *var)
{
    void (*func)() = dlsym(var->handle, "client_event_logged_in");
    func("test1234", "test");
}

void logout(struct data *var)
{
    printf("Here is the logout\n");
}

void user(struct data *var)
{
    printf("Here is the user\n");
}

void users(struct data *var)
{
    printf("Here is the users\n");
}

void send(struct data *var)
{
    printf("Here is the send\n");
}

void messages(struct data *var)
{
    printf("Here is the messages\n");
}

void subscribe(struct data *var)
{
    printf("Here is the subscribe\n");
}

void subscribed(struct data *var)
{
    printf("Here is the subscribed\n");
}

void unsubscribe(struct data *var)
{
    printf("Here is the unsubscribe\n");
}

void use(struct data *var)
{
    printf("Here is the use\n");
}

void create(struct data *var)
{
    printf("Here is the create\n");
}

void info(struct data *var)
{
    printf("Here is the info\n");
}

void list(struct data *var)
{
    printf("Here is the list\n");
}