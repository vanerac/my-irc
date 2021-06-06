/*
** EPITECH PROJECT, 2021
** subscribe
** File description:
** subscribe
*/

#include "commands.h"
#include "message.h"
#include "logging_server.h"

void command_subscribe(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    char *buffer = NULL;
    enum command_return ret_val = SUCCESS;

    if (!args || !args[0]) {
        send_message(session->socket, "665 invalid args", RESPONSE, INVALID);
        return;
    }
    list_t *node = node_find_fn(global->teams, find_by_uuid, args[0]);

    char user_uuid[37];
    char team_uuid[37];
    if (!node) {
        asprintf(&buffer, "402 \"%s\"", args[0]);
        send_message(session->socket, buffer, RESPONSE, SUBSCRIBE);
        return;
    }
    t_teams *team = node->data;
    if (team->subscribers)
        ret_val = node_append_data(team->subscribers, session) ? SUCCESS :
            SYSTEM_ERROR;
    else
        ret_val = (team->subscribers = (node_list_create(session))) ? SUCCESS :
            SYSTEM_ERROR;
    if (ret_val != SUCCESS) {
        send_message(session->socket, "666 \"system error\"", RESPONSE,
            INVALID);
        return;
    }
    uuid_unparse(team->uid, team_uuid);
    uuid_unparse(session->user_data->uid, user_uuid);
    server_event_user_subscribed(team_uuid, user_uuid);
    asprintf(&buffer, "200 \"%s\" \"%s\"", user_uuid, team_uuid);
    send_message(session->socket, buffer, RESPONSE, SUBSCRIBE);
    free(buffer);
}