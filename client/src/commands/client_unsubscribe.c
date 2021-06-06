/*
** EPITECH PROJECT, 2021
** client unsubscribe
** File description:
** client_unsubscribe
*/

#include "client.h"

void unsubscribe(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 2)
                client_print_unsubscribed(args[0], args[1]);
            break;
        case 402:
            if (get_array_size(args) >= 1)
                client_error_unknown_team(args[0]);
            break;
    }
    free_table(args);
}