/*
** EPITECH PROJECT, 2021
** info command
** File description:
** info
*/

#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

enum command_return thread_info(session_t *session)
{
    char *buff = NULL;

    asprintf(&buff, "216 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"",
        session->current_thread->uid, session->user_data->uid,
        session->current_thread->created_at, session->current_thread->title,
        session->current_thread->body);
    send_message(session->socket, buff, RESPONSE, INFO);
    free(buff);
    return SUCCESS;
}

enum command_return channel_info(session_t *session)
{
    char *buff = NULL;

    asprintf(&buff, "215 \"%s\" \"%s\" \"%s\"", session->current_channel->uid,
        session->current_channel->name, session->current_channel->desc);
    send_message(session->socket, buff, RESPONSE, INFO);
    free(buff);
    return SUCCESS;
}

enum command_return team_info(session_t *session)
{
    char *buff = NULL;

    asprintf(&buff, "214 \"%s\" \"%s\" \"%s\"", session->current_team->uid,
        session->current_team->name, session->current_team->desc);
    send_message(session->socket, buff, RESPONSE, INFO);
    free(buff);
    return SUCCESS;
}

enum command_return user_info(session_t *session)
{
    char *buff = NULL;
    char uuid[37];

    uuid_unparse(session->user_data->uid, uuid);

    asprintf(&buff, "213 \"%s\" \"%s\" \"%i\"", uuid,
        session->user_data->username, session->logged ? 1 : 0);
    send_message(session->socket, buff, RESPONSE, INFO);
    free(buff);
    return SUCCESS;
}

enum command_return call_info(session_t *session)
{
    if (session->current_thread)
        return thread_info(session);
    if (session->current_channel)
        return channel_info(session);
    if (session->current_team)
        return team_info(session);
    else
        return user_info(session);
}

void command_info(t_global *global, session_t *session, char **args)
{
    (void) args;
    (void) global;
    enum command_return ret_val = SUCCESS;

    if (session->error != NO_ERROR) {
        send_error_to_client(session);
        return;
    }
    ret_val = call_info(session);
    if (ret_val != SYSTEM_ERROR)
        send_message(session->socket, "666 \"system error\"", RESPONSE, LIST);
}