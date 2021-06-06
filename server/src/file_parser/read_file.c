/*
** EPITECH PROJECT, 2021
** C
** File description:
** read_file.c file
*/

#include <unistd.h>
#include <logging_server.h>
#include <server.h>
#include "file_parser.h"

t_messages *parse_reply(char **args)
{
    t_messages *ret = malloc(sizeof(t_messages));

    if ((!check_type(args, REPLY) && !check_type(args, REPLY)) ||
        !args_len(args, 7))
        return NULL;
    ret->type = REPLY;
    uuid_parse(args[2], ret->uid);
    uuid_parse(args[3], ret->author_uuid);
    ret->created_at = atoll(
        args[4]), ret->title = args[5], ret->body = args[6], ret->m_type = atoi(
        args[1]);
    return ret;
}

t_user *parse_user(char **args)
{
    t_user *ret = malloc(sizeof(t_user));

    if (!check_type(args, USER) || !args_len(args, 3))
        return NULL;
    ret->type = USER;
    uuid_parse(args[1], ret->uid);
    ret->username = args[2];
    ret->logged = false;
    char uuid[37];
    uuid_unparse(ret->uid, uuid);
    server_event_user_loaded(uuid, ret->username); // todo maybe change place
    return ret;
}

t_dm *parse_dm(char **args)
{
    if (!check_type(args, DM) || !args_len(args, 3))
        return NULL;
    t_dm *ret = malloc(sizeof(t_dm));

    ret->type = DM;
    uuid_parse(args[1], ret->user_second);
    uuid_parse(args[2], ret->user_first);

    list_t *message = NULL;
    ret->messages = message;

    return ret;
}