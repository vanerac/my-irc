/*
** EPITECH PROJECT, 2021
** command_user
** File description:
** command_user
*/

#include "client.h"

void user(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 3)
                client_print_user(args[0], args[1], atoi(args[2]));
            break;
        case 401:
            client_error_unknown_user(allargs);
            break;
    }
}