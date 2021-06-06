/*
** EPITECH PROJECT, 2021
** create reply
** File description:
** create_reply
*/

#include "server.h"
#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

void notify_reply_created(session_t *session, t_messages *thread)
{
    char *buff = NULL;
    list_t *subs = session->current_team->subscribers;
    session_t *curr = NULL;
    char team_uuid[37];
    char thread_uuid[37];
    char user_uuid[37];

    uuid_unparse(session->current_team->uid, team_uuid);
    uuid_unparse(thread->uid, thread_uuid);
    uuid_unparse(session->user_data->uid, user_uuid);
    asprintf(&buff, "211 \"%s\" \"%s\" \"%s\" \"%s\"", team_uuid, thread_uuid,
        user_uuid, thread->body);
    for (; subs; subs = subs->next) {
        curr = (session_t *) subs->data;
        if (curr->logged) {
            send_message(curr->socket, buff, RESPONSE, CREATE);
        }
    }
    free(buff);
}

static enum command_return create_comment_second_part(session_t *session,
    t_messages *pmessages, t_messages *thread)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;

    if (pmessages->replies)
        ret_val = node_append_data(pmessages->replies, thread) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (pmessages->replies = node_list_create(thread)) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    char t_uuid[37], s_uuid[37];
    uuid_unparse(((t_user *) session->user_data)->uid, s_uuid);
    uuid_unparse(thread->uid, t_uuid);
    asprintf(&ret, "212 \"%s\" \"%s\" \"%ld\" \"%s\"", t_uuid, s_uuid,
        pmessages->created_at, pmessages->body);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    notify_reply_created(session, thread);
    return SUCCESS;
}

enum command_return create_comment(t_messages *pmessages,
    session_t *session, char *arg)
{
    t_messages *thread = malloc(sizeof(t_messages));
    char uuid_m[37], uuid_s[37];
    if (!thread)
        return SYSTEM_ERROR;
    uuid_generate(thread->uid);
    thread->type = REPLY;
    thread->m_type = M_REPLY;
    thread->title = NULL;
    thread->body = arg;
    thread->destination = pmessages;
    thread->author = session->user_data;
    thread->replies = NULL;
    time(&thread->created_at);
    uuid_unparse(pmessages->uid, uuid_m);
    uuid_unparse(session->user_data->uid, uuid_s);
    server_event_reply_created(uuid_m, uuid_s, thread->body);
    return create_comment_second_part(session, pmessages, thread);
}
