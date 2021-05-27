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

void login_ok_200(struct data *var);
void logout_ok_201(struct data *var);
void dm_received_202(struct data *var);
void thread_reply_203(struct data *var);
void event_team_created_204(struct data *var); // Every logged user should receive this event (the creator of the team too)
void event_channel_created_205(struct data *var);
void event_thread_created_206(struct data *var);
void print_users_207(struct data *var);
void print_teams_208(struct data *var);
void print_channels_209(struct data *var);
void print_threads_210(struct data *var);
void print_replies_211(struct data *var);
void print_dm_212(struct data *var);
void unknown_team_213(struct data *var);
void unknown_channel_214(struct data *var);
void unknown_thread_215(struct data *var);
void unknown_user_216(struct data *var);
void no_auth_217(struct data *var);
void already_exist_218(struct data *var);
void info_user_219(struct data *var);
void info_team_220(struct data *var);
void info_channel_221(struct data *var);
void info_thread_222(struct data *var);
void team_created_only_for_creator_223(struct data *var);
void channel_created_only_for_creator_224(struct data *var);
void thread_created_only_for_creator_225(struct data *var);
void reply_created_only_for_creator_226(struct data *var);
void subscribed_created_only_for_creator_227(struct data *var);
void unsubscribed_created_only_for_creator_228(struct data *var);

#endif /* !CLIENT_H_ */