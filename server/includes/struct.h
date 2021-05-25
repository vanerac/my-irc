/*
** EPITECH PROJECT, 2021
** C
** File description:
** struct.h file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "list.h"

typedef int uuid;

typedef struct user {
    uuid uid;
    char *username;
} t_user;

typedef struct session_s {
    int socket;
    bool logged;
    t_user user_data;
} session_t;

typedef struct teams {
    uuid uid;               // uuid of the teams
    char *name;
    char *desc;
    list_t *users;     // list of all users in the team
    list_t *channels;  // list of all channels in the team
} t_teams;

typedef struct channel {
    uuid uid;               // uuid of channel
    list_t *messages;  // list of all channel messages
} t_channel;

typedef struct dm {
    uuid user_first;
    uuid user_second;
    list_t *messages;
} t_dm;

enum message_type {
    THREAD = 0,
    REPLY = 1,
    DM = 2
};

typedef struct messages {
    uuid uid;               // uuid for message
    struct user *source;      // user who send message
    void *destination;           // channel or user
    char *body;             // message
    char *title;               // null if not a thread
    list_t *replies;   // list of replies
    enum message_type type;
} t_messages;

typedef struct global {
    list_t *all_user;  // list of all users
    list_t *teams;     // list of all the teams
    list_t *private_message;   //
} t_global;

#endif /* !STRUCT_H_ */