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

#define UNSET 0

typedef struct data
{
    char *buffer_client;
    char *buffer_server;
    char **splitted_cmd;
    char *login;
    char *team_uuid;
    char *channel_uuid;
    char *thread_uuid;
    int server_fd;
} data;

void client_command_handler(struct data *var);
char **str_to_word_array(char *str, char spliter_char);
int search_command(char *cmd[], char *handle_cmd);
int array_size(char **array);

// int client_event_logged_in(char const *user_uuid, const char *user_name);

void help(struct data *var, void *handle);
void login(struct data *var, void *handle);
void logout(struct data *var, void *handle);
void user(struct data *var, void *handle);
void users(struct data *var, void *handle);
void send(struct data *var, void *handle);
void messages(struct data *var, void *handle);
void subscribe(struct data *var, void *handle);
void subscribed(struct data *var, void *handle);
void unsubscribe(struct data *var, void *handle);
void use(struct data *var, void *handle);
void create(struct data *var, void *handle);
void info(struct data *var, void *handle);
void list(struct data *var, void *handle);

#endif /* !CLIENT_H_ */