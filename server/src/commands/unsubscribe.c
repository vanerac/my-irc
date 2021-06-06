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
    (void) session, (void) args, (void) global;

    CHECK_ARGS(args, 1, session->socket);
    list_t *node = node_find_fn(global->teams, &find_by_uuid, args[0]);
    if (!node) {
        SEND_MESSAGE(session->socket, RESPONSE, UNSUBSCRIBE, "400 \"%s\"\n",
            args[0])
        return;
    }
    t_teams *team = node->data;
    team->subscribers = node_delete_fn(team->subscribers, &find_by_uuid,
        args[0]);
    char user_uuid[37];
    uuid_unparse(session->user_data->uid, user_uuid);
    SEND_MESSAGE(session->socket, RESPONSE, UNSUBSCRIBE, "200 \"%s\" \"%s\"\n",
        user_uuid, args[0])
}