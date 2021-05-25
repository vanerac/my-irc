/*
** EPITECH PROJECT, 2021
** C
** File description:
** list.c file
*/

#include "list.h"

list_t *node_list_create(void *data)
{
    LIST_CHECKPTR(data) NULL;

    list_t *ret = malloc(sizeof(list_t));
    LIST_CHECKPTR(ret) NULL;

    ret->data = data;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}

bool node_insert_data(list_t *list, void *data)
{
    LIST_CHECKPTR(list) false;
    LIST_CHECKPTR(data) false;

    list_t *new = malloc(sizeof(list_t));

    LIST_CHECKPTR(new) false;

    new->data = data;
    new->next = list->next;
    list->next = new;
    new->prev = list;

    return true;
}

bool node_append_data(list_t *list, void *data)
{
    LIST_CHECKPTR(list) false;
    LIST_CHECKPTR(data) false;
    list_t *i = list;
    for (; i->next; i = i->next);
    return node_insert_data(i, data);
}



