/*
** EPITECH PROJECT, 2021
** essage receive
** File description:
** message_receive
*/

#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"

static enum info_command get_command_enum(uint8_t command)
{
    enum info_command res = INVALID;

    res = (command == 0x01) ? HELP
        : (command == 0x02) ? LOGIN
        : (command == 0x03) ? LOGOUT
        : (command == 0x04) ? USERS
        : (command == 0x05) ? USER
        : (command == 0x06) ? SEND
        : (command == 0x07) ? MESSAGES
        : (command == 0x08) ? SUBSCRIBE
        : (command == 0x09) ? SUBSCRIBED
        : (command == 0x0A) ? UNSUBSCRIBE
        : (command == 0x0B) ? USE
        : (command == 0x0C) ? CREATE
        : (command == 0x0D) ? LIST
        : (command == 0x0E) ? INFO
        : INVALID;
    return res;
}

static enum info_data get_command(uint8_t command)
{
    if (command == 0x01)
        return COMMAND;
    return RESPONSE;
}

static int get_info_size(uint8_t *str)
{
    int size = 0;

    size = (int)str[2] * 256 + (int)str[3];
    return size;
}

static char *get_args(int client_fd, int size)
{
    char *buffer = buffer = malloc(sizeof(char) * size + 1);

    if (!buffer)
        return NULL;
    if (read(client_fd, buffer, size) != size)
        return NULL;
    buffer[size] = '\0';
    return buffer;
}

bool read_message(message_info_t *info, int client_fd)
{
    uint8_t info_read[4] = {0};
    int size = 0;

    if (read(client_fd, info_read, 4) != 4)
        return false;
    info->is_command = get_command(info_read[0]);
    info->command = get_command_enum(info_read[1]);
    if ((size = get_info_size(info_read)) == 0) {
        info->args = strdup("");
        return true;
    }
    info->args = get_args(client_fd, size);
    if (!info->args)
        return false;
    return true;
}