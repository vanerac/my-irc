/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <libnet.h>

int main(int ac, char **ag)
{
    if (ac < 2)
        return 84;
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");;
    serverAddr.sin_port = htons(atoi(ag[1]));

    if (!connect(fd, (const struct sockaddr *) &serverAddr,
        sizeof(serverAddr))) {

        char *buffer = calloc(sizeof(char), 200);
        while (buffer) {
            read(fd, buffer, 200);
            printf("buff server => %s\n", buffer);

            memset(buffer, 0, 200);

            read(0, buffer, 200);
            printf("my buffer => %s\n", buffer);
            write(fd, buffer, strlen(buffer));
        }
    } else
        perror("connect");
}