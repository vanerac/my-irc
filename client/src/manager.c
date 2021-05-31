/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** manager
*/

#include "client.h"

int search_command(char *cmd[], char *handle_cmd)
{
    int return_value = -1;

    for (int i = 0; i < 29; i++){
        if (strcmp(handle_cmd, cmd[i]) == 0)
            return_value = i;
    }
    return (return_value);
}

void server_handler(struct data *var)
{
    var->handle = dlopen("./libs/myteams/libmyteams.so", RTLD_LAZY);
    char *cmd[] = {"/help", "/login", "/logout", "/user", "/users", "/send",
                "/messages", "/subscribe", "/subscribed", "/unsubscribe",
                "/use", "/create", "/info", "/list"};

    var->splitted_cmd = str_to_word_array(var->buffer_server, ' ');
    int to_point = search_command(cmd, var->splitted_cmd[0]);

    if (to_point == -1){
        printf("Unkwown Command\n");
        return;
    } else {
        void (*fun_ptr_arr[])(struct data *) = {help, login , logout, user,
        users,send, messages, subscribe, subscribed, unsubscribe, use, create,
        info, list};

        (*fun_ptr_arr[to_point])(var);
    }
}