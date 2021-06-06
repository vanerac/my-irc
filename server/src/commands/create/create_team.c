/*
** EPITECH PROJECT, 2021
** create team
** File description:
** create_team
*/

#include "server.h"
#include "logging_server.h"
#include "commands.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

static void notify_team_created(t_global *global, t_teams *team)
{
    list_t *all_sess = global->sessions;
    session_t *sess = NULL;
    char *buffer = NULL;
    char uuid[37];

    uuid_unparse(team->uid, uuid);
    asprintf(&buffer, "205 \"%s\" \"%s\" \"%s\"", uuid, team->name,
        team->desc);
    if (all_sess)
        all_sess = all_sess->next;
    for (; all_sess; all_sess = all_sess->next) {
        sess = (session_t *) all_sess->data;
        if (sess->logged) {
            send_message(sess->socket, buffer, RESPONSE, CREATE);
        }
    }
    free(buffer);
}

static enum command_return create_team_second_part(t_global *global,
    session_t *session, t_teams *team, char *uuid)
{
    char *ret = NULL;
    enum command_return ret_val = SUCCESS;

    if (global->teams)
        ret_val =
            node_append_data(global->teams, team) ? SUCCESS : SYSTEM_ERROR;
    else
        ret_val =
            (global->teams = node_list_create(team)) ? SUCCESS : SYSTEM_ERROR;
    if (ret_val != SUCCESS)
        return SYSTEM_ERROR;
    asprintf(&ret, "206 \"%s\" \"%s\" \"%s\"", uuid, team->name, team->desc);
    send_message(session->socket, ret, RESPONSE, CREATE);
    free(ret);
    notify_team_created(global, team);
    return SUCCESS;
}

enum command_return create_team(t_global *global, session_t *session,
    char *name, char *desc)
{
    t_teams *team = malloc(sizeof(t_teams));
    char uuid[37];
    if (!team)
        return SYSTEM_ERROR;
    uuid_generate(team->uid);
    team->name = strdup(name);
    team->desc = strdup(desc);
    team->channels = NULL;
    team->subscribers = NULL;
    team->type = TEAM;
    uuid_unparse(team->uid, uuid);
    server_event_team_created(uuid, name,
        ((t_user *) session->user_data)->username);
    return create_team_second_part(global, session, team, uuid);
}
