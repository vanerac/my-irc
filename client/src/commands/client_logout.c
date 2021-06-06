/*
** EPITECH PROJECT, 2021
** client_logout.c
** File description:
** client_logout
*/

#include "client.h"

void logout(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 2)
                client_event_logged_out(args[0], args[1]);
            break;
    }
    free_table(args);
}