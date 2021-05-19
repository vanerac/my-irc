/*
** EPITECH PROJECT, 2021
** C
** File description:
** list_find.c file
*/

#include "list.h"

list_t *node_find_data(list_t *list, void *data)
{
    LIST_CHECKPTR(list) NULL;
    LIST_CHECKPTR(data) NULL;

    list_t *ptr = list;
    for (; ptr && ptr->data != data; ptr = ptr->next);

    return ptr;
}

list_t *node_find_fn(list_t *list, CHECKFN, void *data)
{
    LIST_CHECKPTR(list) NULL;
    LIST_CHECKPTR(check_fn) NULL;

    list_t *ptr = list;
    for (; ptr && !check_fn(ptr->data, data); ptr = ptr->next);

    return NULL;
}