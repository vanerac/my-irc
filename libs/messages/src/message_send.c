/*
** EPITECH PROJECT, 2021
** message send
** File description:
** message_send
*/

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"
#include "command_enum.h"

uint8_t *send_command(char *buffer, int *total)
{
    char *command = strtok(buffer, " \n");
    char *end = strtok(NULL, "\n");
    int size = get_size_uint(end);
    uint8_t *to_send = malloc(sizeof(uint8_t) * size);

    if (!command || !to_send)
        return NULL;
    to_send[0] = 0x01;
    to_send[1] = char_command_to_uint(command);
    convert_size(to_send, end);
    convert_args(to_send, end);
    *total = size;
    return to_send;
}

uint8_t *send_response(char *buffer, int *total, enum command_e command)
{
    int size = get_size_uint(buffer);
    uint8_t *to_send = malloc(sizeof(uint8_t) * size);

    if (!to_send)
        return NULL;
    to_send[0] = 0x00;
    to_send[1] = command_enum_to_uint(command);
    convert_size(to_send, buffer);
    convert_args(to_send, buffer);
    *total = size;
    return to_send;
}

int send_message(int fd, char *buffer, enum info_data data,
        enum command_e command)
{
    uint8_t *to_send = NULL;
    int size = 0;

    if (!buffer)
        return -1;
    if (data == COMMAND)
        to_send = send_command(buffer, &size);
    else
        to_send = send_response(buffer, &size, command);
    if (!to_send)
        return -1;
    write(fd, to_send, size);
    free(to_send);
    return 0;
}