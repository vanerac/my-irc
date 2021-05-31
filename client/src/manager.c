/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** manager
*/

#include "client.h"

void server_handler(message_info_t *info, lib_func_client_t *lib_client)
{
    char **args = NULL;
    
    if (info->args) {
        if (!(args = str_to_word_array(info->args, ' ')))
            return;
    }
    for (int i = 0; i < 15; i++) {
        if (func_ptr_client[i].command == info->command)
            (*func_ptr_client[i].func)(args, lib_client);
            return;
    }
    
    // char *cmd[] = {"/help", "/login", "/logout", "/user", "/users", "/send",
    //             "/messages", "/subscribe", "/subscribed", "/unsubscribe",
    //             "/use", "/create", "/info", "/list"};

    // char **splitted_cmd = str_to_word_array(var->buffer_server, ' ');
    // int to_point = search_command(cmd, info->command);

    // if (to_point == -1){
        // printf("Unkwown Command\n");
        // return;
    // } else {
        // void (*fun_ptr_arr[])(struct data *) = {help, login , logout, user,
        // users,send, messages, subscribe, subscribed, unsubscribe, use, create,
        // info, list};

        // (*fun_ptr_arr[to_point])(var);
    // }
}