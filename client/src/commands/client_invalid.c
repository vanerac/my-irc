/*
** EPITECH PROJECT, 2021
** client_invalid.c
** File description:
** client_invalid
*/

#include "client.h"

void invalid(int code, char *allargs)
{
    if (!allargs)
        return;
    switch (code) {
        case 220:
            printf("%s\n", allargs);
            break;
        case 665:
            printf("%s\n", allargs);
            break;
        case 400:
            client_error_unauthorized();
            break;
        case 399:
            printf("%s\n", allargs);
            break;
    }
}