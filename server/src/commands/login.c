/*
** EPITECH PROJECT, 2021
** C
** File description:
** login.c file
*/

#include <logging_server.h>
#include <string.h>
#include "commands.h"
#include "message.h"

int asprintf(char **strp, const char *fmt, ...);

static t_user *create_user(t_global *global, char *username)
{
    t_user *ret = malloc(sizeof(t_user));
    char uuid[37];

    if (!ret || !username)
        return NULL;
    uuid_generate(ret->uid);
    ret->type = USER;
    ret->username = strdup(username);
    NODE_ADD(global->all_user, ret)
    ret->logged = true;
    uuid_unparse(ret->uid, uuid);
    server_event_user_created(uuid, ret->username);
    return ret;
}

static bool find_by_username(void *it, void *data)
{
    return !strcmp(((t_user *) it)->username, (char *) data);
}

static bool find_by_username_session(void *it, void *data)
{
    if (!((session_t *) it)->user_data)
        return false;
    return !strcmp(((session_t *) it)->user_data->username, (char *) data);
}

void login_second_part(t_global *global, session_t *session,
    char **args, list_t *user)
{
    char *buff = NULL;
    char uuid[37];

    if (user)
        session->user_data = (t_user *) user->data;
    else
        session->user_data = create_user(global, args[0]);
    if (!session->user_data)
        return;
    session->logged = true;
    session->user_data->logged = true;
    uuid_unparse(session->user_data->uid, uuid);
    server_event_user_logged_in(uuid);
    asprintf(&buff, "200 \"%s\" \"%s\"", uuid, args[0]);
    send_message(session->socket, buff, RESPONSE, LOGIN);
    free(buff);
}

void command_login(t_global *global, session_t *session, char **args)
{
    list_t *user = NULL;

    CHECK_ARGS(args, 1, session->socket)
    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    if (strlen(args[0]) > 32) {
        send_message(session->socket, "665 too long args", RESPONSE, INVALID);
        return;
    }
    if (session->logged ||
        node_find_fn(global->sessions, &find_by_username_session, args[0]))
        return (void) send_message(session->socket, "407 already logged",
            RESPONSE, LOGIN);
    user = node_find_fn(global->all_user, &find_by_username, args[0]);
    login_second_part(global, session, args, user);
}