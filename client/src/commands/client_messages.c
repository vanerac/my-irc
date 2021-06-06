/*
** EPITECH PROJECT, 2021
** client_messages
** File description:
** client_messages
*/

#include "client.h"

void messages(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    switch (code) {
        case 200:
            if (get_array_size(args) >= 3)
                client_private_message_print_messages(args[0],
                (time_t)atol(args[1]), args[2]);
            break;
        case 401:
            if (get_array_size(args) >= 1)
                client_error_unknown_user(args[0]);
            break;
    }
    free_table(args);
}
