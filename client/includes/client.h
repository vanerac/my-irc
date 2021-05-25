/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

// #define UNSET 0

typedef struct data
{
    char *buffer_client;
    char *buffer_server;
    char **splitted_cmd;
    // char *user_uuid; // to keep ?
    void *handle;
    int server_fd;
} data;

void server_handler(struct data *var);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
int array_size(char **array);

void help(struct data *var);
void login(struct data *var);
void logout(struct data *var);
void user(struct data *var);
void users(struct data *var);
void send(struct data *var);
void messages(struct data *var);
void subscribe(struct data *var);
void subscribed(struct data *var);
void unsubscribe(struct data *var);
void use(struct data *var);
void create(struct data *var);
void info(struct data *var);
void list(struct data *var);

#endif /* !CLIENT_H_ */