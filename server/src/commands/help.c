/*
** EPITECH PROJECT, 2021
** help
** File description:
** help
*/

#include "commands.h"
#include "message.h"

void command_help(t_global *global, session_t *session, char **args)
{
    (void) session, (void) args, (void) global;

    char *h = "200 /help -> show help\n/login 'user' -> set the user used by"
    " client\n/logout -> disconnect the client from the server\n"
    "/users -> list of all users that exist\n/user 'user_uuid' -> get"
    " information about a user\n/send 'user_uuid' 'message_body' -> send"
    " a message to a user\n/messages 'user_uuid' -> list all messages with"
    " a user\n/subscribe 'team_uuid' -> subscribe to a team\n/subscribed ?"
    "'team_uuid' -> list all subscribed teams or list all users subscribed"
    " to a team\n/unsubscribe 'team_uuid' -> unsubscribe from a team\n"
    "/use ? 'team_uuid' ?'channel_uuid' ?'thread_uuid' -> use specify a "
    "context team/channel/thread\n/create -> create team/channel/thread\n"
    "/list -> list existing teams/channels/threads\n/info -> display info"
    " about users/team/channel/thread\n";

    send_message(session->socket, h, RESPONSE, HELP);
}