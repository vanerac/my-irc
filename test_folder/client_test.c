/*
** EPITECH PROJECT, 2021
** client
** File description:
** client_test
*/

#include "../libs/sockets/includes/sockets.h"
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "message.h"

// uint8_t get_command(char *to_convert)
// {
//     uint8_t res = 0x00;

//     res = (strcmp("/help", to_convert) == 0) ? 0x01
//         : (strcmp("/login", to_convert) == 0) ? 0x02
//         : (strcmp("/logout", to_convert) == 0) ? 0x03
//         : (strcmp("/users", to_convert) == 0) ? 0x04
//         : (strcmp("/user", to_convert) == 0) ? 0x05
//         : (strcmp("/send", to_convert) == 0) ? 0x06
//         : (strcmp("/messages", to_convert) == 0) ? 0x07
//         : (strcmp("/subscribe", to_convert) == 0) ? 0x08
//         : (strcmp("/subscribed", to_convert) == 0) ? 0x09
//         : (strcmp("/unsubscribe", to_convert) == 0) ? 0x0A
//         : (strcmp("/use", to_convert) == 0) ? 0x0B
//         : (strcmp("/create", to_convert) == 0) ? 0x0C
//         : (strcmp("/list", to_convert) == 0) ? 0x0D
//         : (strcmp("/info", to_convert) == 0) ? 0x0E
//         : 0x30;
//     return res;
// }

// void convert_size(uint8_t *to_send, char *end)
// {
//     if (!end) {
//         to_send[2] = 0x00;
//         to_send[3] = 0x00;
//     } else {
//         to_send[2] = (uint8_t)(strlen(end) / 256);
//         to_send[3] = (uint8_t)(strlen(end) % 256);
//     }
// }

// void convert_args(uint8_t *to_send, char *end)
// {
//     if (!end)
//         return;
//     for (int i = 0; end[i]; i++) {
//         to_send[i + 4] = (uint8_t)end[i];
//     }
// }

// size_t get_size_uint(char *str)
// {
//     size_t size = 0;

//     if (!str)
//         size = 4;
//     else
//         size = strlen(str) + 4;
//     return size;
// }

// uint8_t is_command(int status)
// {
//     if (status == 1)
//         return 0x01;
//     return 0x00;
// }

// int send_message(int fd, char *buffer, int status)
// {
//     char *command = strtok(buffer, " \n");
//     char *end = strtok(NULL, "\n");
//     int size = get_size_uint(end);
//     uint8_t *to_send = malloc(sizeof(uint8_t) * size);
    
//     if (!to_send)
//         return -1;
//     to_send[0] = is_command(status);
//     to_send[1] = get_command(command);
//     convert_size(to_send, end);
//     convert_args(to_send, end);
//     write(fd, to_send, size);
//     free(to_send);
// }

int main(int argc, char **av)
{
    int fd = client_create(atoi(av[2]), av[1]);
    message_info_t info;
    char *buffer = malloc(sizeof(char) * 1024);

    if (!buffer)
        return 84;
    while (1) {
        int ret = read(0, buffer, 1024);
        if (ret == -1)
            return 84;
        if (ret != 0) {
            buffer[ret] = '\0';
            send_message(fd, buffer, COMMAND, INVALID);
            read_message(&info, fd);
            printf("message = %s, %i\n", info.args, info.command);
            // test(&info);
        }
        printf("restart\n");
    }
}