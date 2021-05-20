/*
** EPITECH PROJECT, 2021
** C
** File description:
** list.h file
*/

#ifndef C_LIST_H
#define C_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct list_s list_t;

struct list_s {
    void *data;
    struct list_s *next;
    struct list_s *prev;
};

#define LIST_CHECKPTR(ptr) \
    if (!(ptr))       \
        return

#define CHECKFN bool(*check_fn)(void *iterator, void *value)

list_t *node_list_create(void *data);

bool node_append_data(list_t *list, void *data);

bool node_insert_data(list_t *list, void *data);

//void *pop_node(list_t *list);

void node_delete(list_t *node);

void node_delete_data(list_t *list, void *data);

void node_delete_fn(list_t *list, CHECKFN, void *data);

list_t *node_find_data(list_t *list, void *data);

list_t *node_find_fn(list_t *list, CHECKFN, void *data);

#endif //C_LIST_H