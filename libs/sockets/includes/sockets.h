/*
** EPITECH PROJECT, 2021
** C
** File description:
** sockets.h file
*/

#ifndef C_SOCKETS_H
#define C_SOCKETS_H

int socket_create(void);
int socket_bind(int socket_fd, int port);
int socket_listen(int socket_fd);
int socket_connect(int client_fd, int port, char *host);
int socket_accept(int server_fd);

int server_create(int port);
int client_create(int port, char *host);

#endif //C_SOCKETS_H
