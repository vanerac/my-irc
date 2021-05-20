/*
** EPITECH PROJECT, 2021
** C
** File description:
** sockets.c file
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int socket_create(void)
{
    int opt = 1;
    int sockfd = 0;
    struct protoent *protocol = getprotobyname("TCP");

    if (!protocol) {
        perror("error protocol");
        return -1;
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1) {
        perror("can't create socket\n");
        return -1;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
        perror("error setsockopt\n");
        close(sockfd);
        return -1;
    }
    return sockfd;
}

int socket_bind(int socket_fd, int port)
{
    struct sockaddr_in my_addr;

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socket_fd, (const struct sockaddr *)&my_addr,
            sizeof(my_addr)) == -1) {
        perror("error bind\n");
        close(socket_fd);
        return -1;
    }
    return 0;
}

int socket_listen(int socket_fd)
{
    if (listen(socket_fd, 4) == -1) {
        perror("listen error\n");
        close(socket_fd);
        return -1;
    }
    return 0;
}

int socket_connect(int client_fd, int port, char *host)
{
    struct sockaddr_in my_addr;

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &my_addr.sin_addr) != 1) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
    if (connect(client_fd, (const struct sockaddr *)&my_addr,
                sizeof(my_addr)) == -1) {
        perror("error connect\n");
        return -1;
    }
    return 0;
}

int socket_accept(int server_fd)
{
    int client_sock = 0;
    struct sockaddr_in my_client;
    int addrlen = sizeof(my_client);

    if ((client_sock = accept(server_fd, (struct sockaddr *)&my_client,
        (socklen_t *)&addrlen)) == -1) {
        perror("error accept");
        close(server_fd);
        return -1;
    }
    return client_sock;
}