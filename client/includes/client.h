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
    void (*func)(char *code, char *args, lib_func_client_t *lib_client);
} client_func_ptr_t;

extern const client_func_ptr_t func_ptr_client[15];

void server_handler(message_info_t *info, lib_func_client_t *lib_client);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
int array_size(char **array);

void invalid(char *code, char *allargs, lib_func_client_t *lib_client);
void help(char *code, char *allargs, lib_func_client_t *lib_client);
void login(char *code, char *allargs, lib_func_client_t *lib_client);
void logout(char *code, char *allargs, lib_func_client_t *lib_client);
void users(char *code, char *allargs, lib_func_client_t *lib_client);
void user(char *code, char *allargs, lib_func_client_t *lib_client);
void send(char *code, char *allargs, lib_func_client_t *lib_client);
void messages(char *code, char *allargs, lib_func_client_t *lib_client);
void subscribe(char *code, char *allargs, lib_func_client_t *lib_client);
void subscribed(char *code, char *allargs, lib_func_client_t *lib_client);
void unsubscribe(char *code, char *allargs, lib_func_client_t *lib_client);
void use(char *code, char *allargs, lib_func_client_t *lib_client);
void create(char *code, char *allargs, lib_func_client_t *lib_client);
void list(char *code, char *allargs, lib_func_client_t *lib_client);
void info(char *code, char *allargs, lib_func_client_t *lib_client);

void create_team(char **args, lib_func_client_t *lib_client);
void create_channel(char **args, lib_func_client_t *lib_client);
void create_thread(char **args, lib_func_client_t *lib_client);
void create_reply_to_thread(char **args, lib_func_client_t *lib_client);


#endif /* !CLIENT_H_ */