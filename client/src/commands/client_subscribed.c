/*
** EPITECH PROJECT, 2021
** client subscribed
** File description:
** client_subscribed
*/

#include "client.h"

void subscribed(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 201:
            if (get_array_size(args) >= 3)
                client_print_teams(args[0], args[1], args[2]);
            break;
        case 202:
            if (get_array_size(args) >= 3)
                client_print_users(args[0], args[1], atoi(args[2]));
            break;
        case 402:
            client_error_unknown_team(args[0]);
            break;
    }
    free_table(args);
}