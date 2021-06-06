/*
** EPITECH PROJECT, 2021
** client_help.c
** File description:
** client_help
*/

#include "client.h"

void help(int code, char *allargs)
{
    switch (code) {
        case 200:
            printf("%s", allargs);
            break;
        // case 400:
            // client_error_unauthorized();
            // break;
    }
}