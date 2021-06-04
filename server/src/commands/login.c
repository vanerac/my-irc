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

void command_logout(t_global *global, session_t *session, char **args
)
{
    (void) global, (void) args;
    char uuid[37];
    char *ret = NULL;
    uuid_unparse(session->user_data->uid, uuid);
    server_event_user_logged_out(uuid);
    if (!session->user_data)
        return; // not logged in
    asprintf(&ret, "200 \"%s\" \"%s\"", uuid,
        ((t_user *) session->user_data)->username);
    send_message(session->socket, ret, RESPONSE, LOGOUT);
    session->logged = false;
    session->user_data->logged = false;
    session->user_data = NULL;
    //    return SUCCESS;
}

static t_user *create_user(t_global *global, char *username)
{
    if (!username)
        return NULL;
    t_user *ret = malloc(sizeof(t_user));
    char uuid[37];
    if (!ret)
        return NULL;
    uuid_generate(ret->uid);
    ret->type = USER;
    ret->username = strdup(username);
    if (!global->all_user)
        global->all_user = node_list_create(ret);
    else
        node_append_data(global->all_user, ret);
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

void command_login(t_global *global, session_t *session, char **args
)
{
    char uuid[37];
    char *ret = NULL;
    char *username = args[0];
    if (session->logged) {
        // already logged in, error ?
    }
    if (session->logged ||
        node_find_fn(global->sessions, &find_by_username_session, username)) {
        send_message(session->socket, "407 \"already logged\"", RESPONSE,
            LOGIN);
        return; // todo
    }

    list_t *user = node_find_fn(global->all_user, &find_by_username, username);

    if (user)
        session->user_data = (t_user *) user->data;
    else
        session->user_data = create_user(global, username);

    if (!session->user_data)
        return; // todo error ???
    session->logged = true;
    uuid_unparse(session->user_data->uid, uuid);
    asprintf(&ret, "200 \"%s\" \"%s\"", uuid, username);
    server_event_user_logged_in(uuid);
    send_message(session->socket, ret, RESPONSE, LOGIN);
    //    return SUCCESS;
}

