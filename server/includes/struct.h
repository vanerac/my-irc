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
    MESSAGE
};

typedef struct __attribute__((__packed__)) user {
    enum data_type type;
    uuid uid;
    char *username;
} t_user;

typedef struct __attribute__((__packed__)) teams {
    enum data_type type;
    uuid uid;
    char *name;
    char *desc;
    list_t *users;
    list_t *channels;
} t_teams;

typedef struct __attribute__((__packed__)) channel {
    enum data_type type;
    uuid uid;
    list_t *messages;
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

// todo demande a troncy
typedef struct /*__attribute__((__packed__)) */messages {
    enum data_type type;
    uuid uid;
    struct user *author;
    void *destination;
    char *body;
    char *title;
    time_t created_at;
    list_t *replies;
    enum message_type m_type;
} t_messages;

// typedef struct __attribute__((__packed__)) libfunctions {
    // char *name;
    // void (*func)();
// } libfunctions_t;

typedef struct global {
    list_t *all_user;
    list_t *teams;
    list_t *private_message;
    list_t *sessions;
    // libfunctions_t *lib_func;
} t_global;

#endif /* !STRUCT_H_ */