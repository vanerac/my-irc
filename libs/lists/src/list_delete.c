/*
** EPITECH PROJECT, 2021
** C
** File description:
** list_delete.c file
*/

#include <stdio.h>
#include "list.h"

list_t *node_delete_data(list_t *list, void *data)
{
    LIST_CHECKPTR(data) list;

    for (list_t *ptr = list; ptr; ptr = ptr->next)
        if (ptr->data == data)
            return node_delete(list, ptr);
    return list;
}

list_t *node_delete(list_t *list, list_t *node)
{
    LIST_CHECKPTR(node) list;
    list_t *next = node->next;
    list_t *prev = node->prev;

    if (next)
        next->prev = prev;
    if (prev)
        prev->next = next;

    free(node);
    return node == list ? next : list;
}

list_t *node_delete_fn(list_t *list, CHECKFN, void *data)
{
    LIST_CHECKPTR(check_fn) list;
    LIST_CHECKPTR(list) list;

    for (list_t *l = list; l; l = l->next)
        if (check_fn(l->data, data))
            return node_delete(list, l);

    return list;
}