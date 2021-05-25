/*
** EPITECH PROJECT, 2021
** C
** File description:
** sockets.h file
*/

#ifndef C_SOCKETS_H
#define C_SOCKETS_H

#include <stddef.h>

#define RD_SIZE 1024;

int socket_create(void);
int socket_bind(int socket_fd, int port);
int socket_listen(int socket_fd);
int socket_connect(int client_fd, int port, char *host);
int socket_accept(int server_fd);

int server_create(int port);
int client_create(int port, char *host);

char *binary_encode(const char *buffer);
char *binary_decode(const char *buffer);

char *socket_read(int socket);
size_t socket_write(int socket, char *buffer);

#endif //C_SOCKETS_H
