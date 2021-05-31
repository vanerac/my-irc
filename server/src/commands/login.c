/*
** EPITECH PROJECT, 2021
** C
** File description:
** login.c file
*/

#include <logging_server.h>
#include <string.h>
#include "commands.h"

enum command_return command_logout(t_global *global, session_t *session,
    char **args
)
{
    (void) args, (void) global;
    server_event_user_logged_out((char const *)session->user_data->uid);
    session->user_data = NULL;
    return SUCCESS;
}

static t_user *create_user(t_global *global, char *username)
{
    t_user *ret = malloc(sizeof(t_user));
    if (!ret)
        return NULL;
    uuid_generate(ret->uid);
    ret->type = USER;
    ret->username = strdup(username);
    node_append_data(global->all_user, ret);
    server_event_user_created((char const *) ret->uid, ret->username);
    return ret;
}

static bool find_by_username(void *it, void *data)
{
    return !strcmp(((t_user *) it)->username, (char *) data);
}

enum command_return command_login(t_global *global, session_t *session,
    char **args
)
{
    char *username = args[0];
    if (session->user_data) {
        // already logged in, error ?
    }
    if (node_find_fn(global->sessions, &find_by_username, username))
        return DOUBLE_AUTH;
    list_t *user = node_find_fn(global->all_user, &find_by_username, username);
    if (user)
        session->user_data = (t_user *) user->data;
    else
        session->user_data = create_user(global, username);

    if (!session->user_data)
        return SYSTEM_ERROR;
    server_event_user_logged_in((char const *) session->user_data->uid);

    return SUCCESS;
}

