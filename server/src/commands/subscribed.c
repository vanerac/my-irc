/*
** EPITECH PROJECT, 2021
** subscribed
** File description:
** subscribed
*/

#include "commands.h"
#include "message.h"

enum command_return display_subscribed_teams(t_global *global,
    session_t *session
)
{
    list_t *all_teams = global->teams;
    t_teams *team = NULL;
    char uuid[37];
    char user_uuid[37];

    uuid_unparse(session->user_data->uid, user_uuid);
    for (; all_teams; all_teams = all_teams->next) {
        team = all_teams->data;
        uuid_unparse(team->uid, uuid);
        if (node_find_fn(team->subscribers, &find_by_uuid, user_uuid)) {
            SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBE,
                "201 \"%s\" \"%s\" \"%s\"\n", uuid, team->name, team->desc);
        }
    }
    return SUCCESS;
}

enum command_return display_subscribers_to_team(t_global *global,
    session_t *session, char *uid
)
{
    list_t *node = node_find_fn(global->teams, find_by_uuid, uid);
    t_teams *team = NULL;
    session_t *user = NULL;
    char uuid[37];

    if (!node) {
        SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBE, "402 \"%s\"", uuid);
        return SUCCESS;
    }
    team = node->data;
    for (list_t *i = team->subscribers; i; i = i->next) {
        user = (session_t *) i->data;
        if (!session->user_data)
            continue;
        uuid_unparse(user->user_data->uid, uuid);
        SEND_MESSAGE(session->socket, RESPONSE, SUBSCRIBED,
            "202 \"%s\" \"%s\" \"%d\"\n", uuid, user->user_data->username,
            user->logged);
    }
    return SUCCESS;
}

void command_subscribed(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;
    enum command_return ret_val = SUCCESS;

    if (args || !args[0]) {
        ret_val = display_subscribed_teams(global, session);
    } else {
        ret_val = display_subscribers_to_team(global, session, args[0]);
    }
    if (ret_val != SUCCESS)
        send_message(session->socket, "666 \"system error\"", RESPONSE,
            INVALID);
}
