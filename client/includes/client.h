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
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ctype.h>

#include "command_enum.h"
#include "message.h"
#include "logging_client.h"

typedef struct data
{
    char *buffer_client;
    char *buffer_server;
    char **splitted_cmd;
    void *handle;
    int server_fd;
} data;

typedef struct client_func_ptr {
    enum command_e command;
    void (*func)(int code, char *args);
} client_func_ptr_t;

extern const client_func_ptr_t func_ptr_client[15];

void server_handler(message_info_t *info);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
void free_table(char **table);
char **split_by_quote(char *str);
int get_array_size(char **array);

void invalid(int code, char *allargs);
void help(int code, char *allargs);
void login(int code, char *allargs);
void logout(int code, char *allargs);
void users(int code, char *allargs);
void user(int code, char *allargs);
void send(int code, char *allargs);
void messages(int code, char *allargs);
void subscribe(int code, char *allargs);
void subscribed(int code, char *allargs);
void subscribed_bis(int code, char **args);
void unsubscribe(int code, char *allargs);
void create(int code, char *allargs);
void create_bis(int code, char **args);
void create_error_response(int code, char **args);
void list(int code, char *allargs);
void list_bis(int code, char **args);
void info(int code, char *allargs);
void info_bis(int code, char **args);

int check_args(int ac, char **ag);

#endif /* !CLIENT_H_ */