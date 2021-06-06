/*
** EPITECH PROJECT, 2021
** unsunscribe
** File description:
** unsibscribe
*/

#include "commands.h"
#include "message.h"

void command_unsubscribe(t_global *global, session_t *session, char **args)
{
    (void) global;
    CHECK_ARGS(args, 1, session->socket);
    list_t *node = node_find_fn(global->teams, &find_by_uuid, args[0]);
    t_teams *team = NULL;
    char *buff = NULL;

    if (!node) {
        asprintf(&buff, "400 \"%s\"\n", args[0]);
        send_message(session->socket, buff, RESPONSE, UNSUBSCRIBE);
        free(buff);
        return;
    }
    team = node->data;
    char user_uuid[37];
    uuid_unparse(session->user_data->uid, user_uuid);
    team->subscribers = node_delete_fn(team->subscribers, &find_by_uuid,
        user_uuid);
    asprintf(&buff, "200 \"%s\" \"%s\"\n", user_uuid, args[0]);
    send_message(session->socket, buff, RESPONSE, UNSUBSCRIBE);
    free(buff);
}
