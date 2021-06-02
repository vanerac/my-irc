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
#include "logging_client.h"

typedef struct data
{
    char *buffer_client;
    char *buffer_server;
    char **splitted_cmd;
    // char *user_uuid; // to keep ?
    void *handle;
    int server_fd;
} data;

// typedef struct __attribute__((__packed__)) lib_func_client {
    // char *name;
    // void (*func)();
// } lib_func_client_t;

typedef struct client_func_ptr {
    enum command_e command;
    void (*func)(char *code, char *args);
} client_func_ptr_t;

extern const client_func_ptr_t func_ptr_client[15];

void server_handler(message_info_t *info);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
int array_size(char **array);

void invalid(char *code, char *allargs);
void help(char *code, char *allargs);
void login(char *code, char *allargs);
void logout(char *code, char *allargs);
void users(char *code, char *allargs);
void user(char *code, char *allargs);
void send(char *code, char *allargs);
void messages(char *code, char *allargs);
void subscribe(char *code, char *allargs);
void subscribed(char *code, char *allargs);
void subscribed_bis(char *code, char **args);
void unsubscribe(char *code, char *allargs);
void create(char *code, char *allargs);
void create_bis(char *code, char **args);
void list(char *code, char *allargs);
void list_bis(char *code, char **args);
void info(char *code, char *allargs);
void info_bis(char *code, char **args);

void create_team(char **args);
void create_channel(char **args);
void create_thread(char **args);
void create_reply_to_thread(char **args);


#endif /* !CLIENT_H_ */