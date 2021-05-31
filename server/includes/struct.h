/*
** EPITECH PROJECT, 2021
** C
** File description:
** struct.h file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <uuid/uuid.h>
#include "list.h"

typedef uuid_t uuid;

enum data_type {
    UNKNOWN,
    USER,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY,
    MESSAGE
};

typedef struct __attribute__((__packed__)) user {
    enum data_type type;
    uuid uid;
    char *username;
} t_user;

typedef struct __attribute__((__packed__)) teams {
    enum data_type type;
    uuid uid;               // uuid of the teams
    char *name;
    char *desc;
    list_t *users;     // list of all users in the team
    list_t *channels;  // list of all channels in the team
} t_teams;

typedef struct __attribute__((__packed__)) channel {
    enum data_type type;
    uuid uid;               // uuid of channel
    list_t *messages;  // list of all channel messages
    char *desc;
    char *name;
} t_channel;

typedef struct __attribute__((__packed__)) dm {
    enum data_type type;
    uuid user_first;
    uuid user_second;
    list_t *messages;
} t_dm;

enum message_type {
    M_THREAD = 0,
    M_REPLY = 1,
    M_DM = 2
};

typedef struct __attribute__((__packed__)) messages {
    enum data_type type;
    uuid uid;               // uuid for message
    struct user *source;      // user who send message
    void *destination;           // channel or user
    char *body;             // message
    char *title;               // null if not a thread
    list_t *replies;   // list of replies
    enum message_type m_type;
} t_messages;

typedef struct global {
    list_t *all_user;  // list of all users
    list_t *teams;     // list of all the teams
    list_t *private_message;   //
} t_global;

#endif /* !STRUCT_H_ */