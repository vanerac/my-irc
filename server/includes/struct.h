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

// todo error management
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef uuid_t uuid;

enum data_type {
    UNKNOWN,
    USER,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY,
    DM,
    MESSAGE,
    SESSION
};

typedef struct user {
    enum data_type type;
    uuid uid;
    char *username;
    bool logged;
} t_user;

typedef struct teams {
    enum data_type type;
    uuid uid;
    char *name;
    char *desc;
    list_t *users;
    list_t *channels;
    list_t *subscribers;
} t_teams;

typedef struct channel {
    enum data_type type;
    uuid uid;
    list_t *messages;
    char *desc;
    char *name;
    t_teams *parent;
} t_channel;

typedef struct dm {
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

typedef struct messages {
    enum data_type type;
    uuid uid;
    struct user *author;
    void *destination;
    char *body;
    char *title;
    time_t created_at;
    list_t *replies;
    enum message_type m_type;
    uuid author_uuid;
} t_messages;

typedef struct global {
    list_t *all_user;
    list_t *teams;
    list_t *private_message;
    list_t *sessions;
} t_global;

#endif /* !STRUCT_H_ */