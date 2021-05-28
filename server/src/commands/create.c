/*
** EPITECH PROJECT, 2021
** C
** File description:
** create.c file
*/

#include <server.h>
#include <commands.h>

static enum command_return create_team(t_global *global, char *name,
    char *desc
)
{
    (void) name, (void) desc, (void) global;
    return SUCCESS;
}

static enum command_return create_channel(t_teams *team, char *arg, char *arg1)
{
    (void) arg, (void) arg1, (void) team;
    return SUCCESS;
}

static enum command_return create_tread(t_channel *pChannel, char *arg,
    char *arg1
)
{
    (void) pChannel, (void) arg, (void) arg1;
    return SUCCESS;
}

static enum command_return create_comment(t_messages *pMessages, char *arg)
{
    (void) pMessages, (void) arg;
    return SUCCESS;
}

enum command_return command_create(t_global *global, session_t *session,
    char **args
)
{
    (void) session, (void) args, (void) global;
    char *first_arg = NULL, *second_arg = NULL; // todo
    if (!session->current_team) {
        return create_team(global, first_arg, second_arg);;
    } else if (!session->current_channel) {
        return create_channel(session->current_team, first_arg, second_arg);
    }
    if (!session->current_thread) {
        return create_tread(session->current_channel, first_arg, second_arg);
    } else {
        return create_comment(session->current_thread, first_arg);
    }
}