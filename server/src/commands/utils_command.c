/*
** EPITECH PROJECT, 2021
** utils for command
** File description:
** utils_command
*/

#include "server.h"
#include "message.h"

int asprintf(char **restrict strp, const char *restrict fmt, ...);

void send_error_to_client(session_t *session)
{
    char *ret = NULL;

    if (session->error == ERROR_TEAM) {
        asprintf(&ret, "402 %s", session->fail_uid);
    }
    if (session->error == ERROR_CHANNEL) {
        asprintf(&ret, "403 %s", session->fail_uid);
    }
    if (session->error == ERROR_THREAD) {
        asprintf(&ret, "404 %s", session->fail_uid);
    }
    send_message(session->socket, ret, RESPONSE, LIST);
    free(ret);
}