/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils_create
*/

#include <string.h>
#include "logging_server.h"
#include "server.h"
#include "commands.h"
#include "message.h"

bool find_by_name(void *it, void *data)
{
    switch (*((enum data_type *) it)) {
    case TEAM:
        return !strcmp(((t_teams *) it)->name, data);
    case CHANNEL:
        return !strcmp(((t_channel *) it)->name, data);
    case THREAD:
        return !strcmp(((t_messages *) it)->title, data);
    default:
        return false;
    }
}