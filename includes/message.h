/*
** EPITECH PROJECT, 2021
** messages include
** File description:
** message
*/

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "command_enum.h"
#include <stdarg.h>

int asprintf(char **restrict strp, const char *restrict fmt, ...);

enum info_data {
    RESPONSE,
    COMMAND
};

typedef struct message_info
{
    enum info_data is_command;
    enum command_e command;
    char *args;
} message_info_t;

bool read_message(message_info_t *info, int client_fd);
int send_message(int fd, char *buffer,
    enum info_data data, enum command_e command);

uint8_t char_command_to_uint(char *to_convert);
uint8_t command_enum_to_uint(enum command_e command);
void convert_size(uint8_t *to_send, char *end);
void convert_args(uint8_t *to_send, char *end);
size_t get_size_uint(char *str);

// #define SEND_MESSAGE(socket, type, command, format_str, ...)    
//         {char *buffer = NULL;                                   
//         asprintf(&buffer, format_str, __VA_ARGS__);             
//         send_message(socket, buffer, type, command);            
//         free(buffer);};

#endif /* !MESSAGE_H_ */