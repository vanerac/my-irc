/*
** EPITECH PROJECT, 2021
** client send
** File description:
** client_send
*/

#include "client.h"

void send(int code, char *allargs)
{
    char **args = split_by_quote(allargs);

    if (!args)
        return;
    // if (array_size(args) > 0) {
    switch (code) {
        case 200:
            if (get_array_size(args) >= 2)
                client_event_private_message_received(args[0], args[1]);
            break;
        case 401:
            if (get_array_size(args) >= 1)
                client_error_unknown_user(args[0]);
            break;
        // case 400:
            // client_error_unauthorized();
            // break;
    }
    free_table(args);
}
