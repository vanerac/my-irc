/*
** EPITECH PROJECT, 2021
** C
** File description:
** file_parser.h file
*/

#ifndef C_FILE_PARSER_H
#define C_FILE_PARSER_H

#include <stdio.h>
#include "struct.h"

#define END_STRUCT UNKNOWN

void write_structure(int fd, void *data, int recursion_levels);
list_t *parse_file(int fd);

void write_team(int fd, t_teams *team, int recursion_levels);
void write_channel(int fd, t_channel *channel, int recursion_levels);
void write_thread(int fd, t_messages *thread, int recursion_levels);
void write_message(int fd, t_messages *messages);
void write_user(int fd, t_user *user);
void write_dm(int fd, t_dm *dm, int recursion_level);


// tools
char **get_args(int fd, bool read);
bool check_type(char **args, enum data_type expected_type);

// returns null if code doesnt correspond
t_teams *parse_team(char **args);
t_channel *parse_channel(char **args);
t_messages *parse_thread(char **args);
t_messages *parse_reply(char **args);
t_user *parse_user(char **args);
t_dm *parse_dm(char **args);

void case_USER(char **args);
void case_TEAM(char **args, t_teams **current_team, list_t **ret);
int case_CHANNEL(char **args, t_teams **current_team, t_channel **current_channel,
t_messages **current_thread);
int case_THREAD(char **args, t_messages **current_thread,
t_channel **current_channel);
void case_DM(char **args, t_dm **current_dm);
int case_MESSAGE(char **args, t_dm **current_dm);
int case_REPLY(char **args, t_messages **current_thread);

#endif //C_FILE_PARSER_H
