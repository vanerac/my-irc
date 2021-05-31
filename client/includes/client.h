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

#include "command_enum.h"
#include "message.h"

typedef struct data
{
    char *buffer_client;
    char *buffer_server;
    char **splitted_cmd;
    // char *user_uuid; // to keep ?
    void *handle;
    int server_fd;
} data;

typedef struct __attribute__((__packed__)) lib_func_client {
    char *name;
    void (*func)();
} lib_func_client_t;

typedef struct client_func_ptr {
    enum command_e command;
    void (*func)(char **args, lib_func_client_t *lib_client);
} client_func_ptr_t;

extern const client_func_ptr_t func_ptr_client[15];

void server_handler(message_info_t *info, lib_func_client_t *lib_client);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
int array_size(char **array);

void invalid(char **args, lib_func_client_t *lib_client);
void help(char **args, lib_func_client_t *lib_client);
void login(char **args, lib_func_client_t *lib_client);
void logout(char **args, lib_func_client_t *lib_client);
void users(char **args, lib_func_client_t *lib_client);
void user(char **args, lib_func_client_t *lib_client);
void send(char **args, lib_func_client_t *lib_client);
void messages(char **args, lib_func_client_t *lib_client);
void subscribe(char **args, lib_func_client_t *lib_client);
void subscribed(char **args, lib_func_client_t *lib_client);
void unsubscribe(char **args, lib_func_client_t *lib_client);
void use(char **args, lib_func_client_t *lib_client);
void create(char **args, lib_func_client_t *lib_client);
void list(char **args, lib_func_client_t *lib_client);
void info(char **args, lib_func_client_t *lib_client);

#endif /* !CLIENT_H_ */