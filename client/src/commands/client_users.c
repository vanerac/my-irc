/*
** EPITECH PROJECT, 2021
** client_users
** File description:
** client_users
*/

#include "client.h"

void users(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 3)
                client_print_users(args[0], args[1], atoi(args[2]));
            break;
    }
    free_table(args);
}