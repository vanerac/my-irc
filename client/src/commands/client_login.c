/*
** EPITECH PROJECT, 2021
** client_login.c
** File description:
** client_login
*/

#include "client.h"

void login(int code, char *allargs)
{
    char **args = NULL;

    if (!allargs)
        return;
    if (code == 407) {
        printf("%s\n", allargs);
        return;
    }
    if (!(args = split_by_quote(allargs)))
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 2)
                client_event_logged_in(args[0], args[1]);
            break;
    }
    free_table(args);
}