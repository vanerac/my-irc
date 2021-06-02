/*
** EPITECH PROJECT, 2021
** finction pointer
** File description:
** function_pointer
*/

#include "client.h"

const client_func_ptr_t func_ptr_client[15] =
{
    {
        .command = INVALID,
        .func = &invalid
    },
    {
        .command = HELP,
        .func = &help
    },
    {
        .command = LOGIN,
        .func = &login
    },
    {
        .command = LOGOUT,
        .func = &logout
    },
    {
        .command = USERS,
        .func = &users
    },
    {
        .command = USR,
        .func = &user
    },
    {
        .command = SEND,
        .func = &send
    },
    {
        .command = MESSAGES,
        .func = &messages
    },
    {
        .command = SUBSCRIBE,
        .func = &subscribe
    },
    {
        .command = SUBSCRIBED,
        .func = &subscribed
    },
    {
        .command = UNSUBSCRIBE,
        .func = &unsubscribe
    },
    {
        .command = CREATE,
        .func = &create
    },
    {
        .command = LIST,
        .func = &list
    },
    {
        .command = INFO,
        .func = &info
    }
};