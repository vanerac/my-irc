/*
** EPITECH PROJECT, 2021
** utils send
** File description:
** utils_send
*/

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"
#include "command_enum.h"

uint8_t char_command_to_uint(char *to_convert)
{
    uint8_t res = 0x00;

    res = (strcmp("/help", to_convert) == 0) ? 0x01
        : (strcmp("/login", to_convert) == 0) ? 0x02
        : (strcmp("/logout", to_convert) == 0) ? 0x03
        : (strcmp("/users", to_convert) == 0) ? 0x04
        : (strcmp("/user", to_convert) == 0) ? 0x05
        : (strcmp("/send", to_convert) == 0) ? 0x06
        : (strcmp("/messages", to_convert) == 0) ? 0x07
        : (strcmp("/subscribe", to_convert) == 0) ? 0x08
        : (strcmp("/subscribed", to_convert) == 0) ? 0x09
        : (strcmp("/unsubscribe", to_convert) == 0) ? 0x0A
        : (strcmp("/use", to_convert) == 0) ? 0x0B
        : (strcmp("/create", to_convert) == 0) ? 0x0C
        : (strcmp("/list", to_convert) == 0) ? 0x0D
        : (strcmp("/info", to_convert) == 0) ? 0x0E
        : 0x00;
    return res;
}

uint8_t command_enum_to_uint(enum command_e command)
{
    uint8_t res = 0x00;

    res = (command == HELP) ? 0x01
        : (command == LOGIN) ? 0x02
        : (command == LOGOUT) ? 0x03
        : (command == USERS) ? 0x04
        : (command == USR) ? 0x05
        : (command == SEND) ? 0x06
        : (command == MESSAGES) ? 0x07
        : (command == SUBSCRIBE) ? 0x08
        : (command == SUBSCRIBED) ? 0x09
        : (command == UNSUBSCRIBE) ? 0x0A
        : (command == USE) ? 0x0B
        : (command == CREATE) ? 0x0C
        : (command == LIST) ? 0x0D
        : (command == INFO) ? 0x0E
        : 0x00;
    return res;
}

void convert_size(uint8_t *to_send, char *end)
{
    if (!end) {
        to_send[2] = 0x00;
        to_send[3] = 0x00;
    } else {
        to_send[2] = (uint8_t)(strlen(end) / 256);
        to_send[3] = (uint8_t)(strlen(end) % 256);
    }
}

void convert_args(uint8_t *to_send, char *end)
{
    if (!end)
        return;
    for (int i = 0; end[i]; i++) {
        to_send[i + 4] = (uint8_t)end[i];
    }
}

size_t get_size_uint(char *str)
{
    size_t size = 0;

    if (!str)
        size = 4;
    else
        size = strlen(str) + 4;
    return size;
}
