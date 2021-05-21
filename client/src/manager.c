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

    for (int i = 0; i < 14; i++){
        if (strcmp(handle_cmd, cmd[i]) == 0)
            return_value = i;
    }
    return (return_value);
}

void client_command_handler(struct data *var)
{
    char *cmd[] = {" /help", "/login", "/logout", "/users", "/user", "/send",
                    "/messages", "/subscribe", "/subscribed", "/unsubscribe",
                    "/use", "/create", "/list", "/info"};

    var->splitted_cmd = str_to_word_array(var->buffer_client, ' ');
    int to_point = search_command(cmd, var->splitted_cmd[0]);

    if (var->login == UNSET && to_point != 1){
        printf("You must set a unsername first ! (/login [username])\n");
        return;
    }

    if (to_point == -1){
        write(0, "Unknow Command\n", 15);
        return;
    } else {
        void (*fun_ptr_arr[])(struct data *) = {help, login , logout, user,
        users,send, messages, subscribe, subscribed, unsubscribe, use, create,
        info, list};
        (*fun_ptr_arr[to_point])(var);
    }
}