/*
** EPITECH PROJECT, 2021
** server
** File description:
** server_test
*/

#include "../libs/sockets/includes/sockets.h"
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "message.h"

// enum info_command get_command_enum(uint8_t command)
// {
//     enum info_command res = INVALID;

//     res = (command == 0x01) ? HELP
//         : (command == 0x02) ? LOGIN
//         : (command == 0x03) ? LOGOUT
//         : (command == 0x04) ? USERS
//         : (command == 0x05) ? USER
//         : (command == 0x06) ? SEND
//         : (command == 0x07) ? MESSAGES
//         : (command == 0x08) ? SUBSCRIBE
//         : (command == 0x09) ? SUBSCRIBED
//         : (command == 0x0A) ? UNSUBSCRIBE
//         : (command == 0x0B) ? USE
//         : (command == 0x0C) ? CREATE
//         : (command == 0x0D) ? LIST
//         : (command == 0x0E) ? INFO
//         : INVALID;
//     return res;
// }

// enum info_data get_command(uint8_t command)
// {
//     if (command == 0x01)
//         return COMMAND;
//     return RESPONSE;
// }

// size_t get_info_size(uint8_t *str)
// {
//     size_t size = 0;

//     size = (int)str[2] * 256 + (int)str[3];
//     return size;
// }

// char *get_args(int client_fd, size_t size)
// {
//     char *buffer = buffer = malloc(sizeof(char) * size + 1);

//     if (!buffer)
//         return NULL;
//     if (read(client_fd, buffer, size) != size)
//         return NULL;
//     buffer[size] = '\0';
//     return buffer;
// }

// bool read_command(message_info_t *info, int client_fd)
// {
//     uint8_t info_read[4] = {0};
//     int size = 0;

//     if (read(client_fd, info_read, 4) != 4)
//         return false;
//     info->is_command = get_command(info_read[0]);
//     info->command = get_command_enum(info_read[1]);
//     if ((size = get_info_size(info_read)) == 0) {
//         info->args = strdup("");
//         return true;
//     }
//     info->args = get_args(client_fd, size);
//     if (!info->args)
//         return false;
//     return true;
// }

bool print_command(enum info_command command)
{
    printf("command %s\n",
        (command == HELP) ? "help"
        : (command == LOGIN) ? "login"
        : (command == LOGOUT) ? "logout"
        : (command == USERS) ? "users"
        : (command == USER) ? "user"
        : (command == SEND) ? "send"
        : (command == MESSAGES) ? "messages"
        : (command == SUBSCRIBE) ? "subscribe"
        : (command == SUBSCRIBED) ? "subscribed"
        : (command == UNSUBSCRIBE) ? "unsubscribe"
        : (command == USE) ? "use"
        : (command == CREATE) ? "create"
        : (command == LIST) ? "list"
        : (command == INFO) ? "info"
        : "unknown command");
    if (command == INVALID)
        return false;
    return true;
}

void exec(message_info_t *info)
{
    if (!info)
        return;
    if (info->is_command == COMMAND) {
        if (!print_command(info->command))
            return;
    }
    if (!info->args)
        return;
    printf("args = '%s'\n", info->args);
}

int main(int argc, char **av)
{
    fd_set rfds;
    int new_client = 0;
    int fd = server_create(atoi(av[1]));

    uint8_t *buff = NULL;
    new_client = socket_accept(fd);
    message_info_t info;

    while (1) {
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);
        FD_SET(new_client, &rfds);

        if (select(new_client + 1, &rfds, NULL , NULL, NULL) == -1) {
            perror("Select error\n");
            close(fd);
            return 84;
        }
        if (FD_ISSET(new_client, &rfds)) {
            if (read_message(&info, new_client) == true) {
                printf("message = %s\n", info.args);
                exec(&info);
                free(buff);
                send_message(new_client, "200 command okay", RESPONSE, SEND);
            }
        }
    }
    return 0;
}