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
t_teams *file_read_team(int fd, int recursion_level);
t_channel *file_read_channel(int fd, int recursion_level);
t_messages *file_read_thread(int fd, int recursion_level);
t_messages *file_read_message(int fd);
t_user *file_read_user(int fd);
t_dm *file_read_dm(int fd, int recursion_level);
//
//
// selective reads, only parses selected data types
list_t *read_all_teams(int fd, int recursion_level);
list_t *read_all_channels(int fd, int recursion_level);
list_t *read_all_threads(int fd, int recursion_level);
list_t *read_all_messages(int fd, int recursion_level);
list_t *read_all_users(int fd, int recursion_level);

#endif //C_FILE_PARSER_H
