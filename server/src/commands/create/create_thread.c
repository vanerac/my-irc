/*
** EPITECH PROJECT, 2021
** create thread
** File description:
** create_thread
*/

#include "server.h"
#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

static void notify_thread_created(session_t *session, t_messages *thread)
{
    char *buff = NULL;
    list_t *subs = session->current_team->subscribers;
    session_t *curr = NULL;
    char t_uuid[37];
    char u_uuid[37];

    uuid_unparse(thread->uid, t_uuid);
    uuid_unparse(session->user_data->uid, u_uuid);
    asprintf(&buff, "209 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"", t_uuid, u_uuid,
        thread->created_at, thread->title, thread->body);
    for (; subs; subs = subs->next) {
        curr = (session_t *) subs->data;
        if (curr->logged) {
            send_message(curr->socket, buff, RESPONSE, CREATE);
        }
    }
    free(buff);
}

static enum command_return create_thread_second_part(t_channel *pchannel,
    session_t *session, t_messages *thread)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;
    char t_uuid[37];
    char s_uuid[37];

    if (pchannel->messages)
        ret_val = node_append_data(pchannel->messages, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (pchannel->messages = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    uuid_unparse(((t_user *) session->user_data)->uid, s_uuid);
    uuid_unparse(thread->uid, t_uuid);
    asprintf(&ret, "210 \"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"", t_uuid, s_uuid,
        thread->created_at, thread->title, thread->body);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    notify_thread_created(session, thread);
    return SUCCESS;
}

enum command_return create_tread(t_channel *pchannel,
    session_t *session, char *arg, char *arg1)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char id_t[37];
    char id_s[37];
    char id_c[37];

    if (!thread)
        return SYSTEM_ERROR;
    if (node_find_fn(session->current_channel, &find_by_name, arg)) {
        send_message(session->socket, "405 already exist", RESPONSE, CREATE);
        return SUCCESS;
    }
    uuid_generate(thread->uid);
    thread->type = THREAD;
    thread->m_type = M_THREAD;
    thread->body = arg1;
    thread->title = arg;
    thread->destination = pchannel;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_copy(thread->author_uuid, session->user_data->uid);
    uuid_unparse(thread->uid, id_t);
    uuid_unparse(session->user_data->uid, id_s);
    uuid_unparse(pchannel->uid, id_c);
    server_event_thread_created(id_c, id_t, id_s, thread->title, thread->body);
    return create_thread_second_part(pchannel, session, thread);
}
