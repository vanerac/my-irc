/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** manager
*/

#include "client.h"

void server_handler(message_info_t *info)
{
    char *code = NULL;
    char *args = NULL;
    
    if (info->args) {
        code = strtok(info->args, " ");
        args = strtok(NULL, "\0");
    }
    if (!code)
        return;
    for (int i = 0; i < 14; i++) {
        if (func_ptr_client[i].command == info->command) {
            (*func_ptr_client[i].func)(code, args);
            return;
        }
    }
}