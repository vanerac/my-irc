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
    list_t *ptr = list;
    for (list_t *next = ptr->next; ptr; ptr = next, next =
        ptr ? ptr->next : NULL);
    return node_delete(list, ptr);
}

list_t *node_delete(list_t *list, list_t *node)
{
    LIST_CHECKPTR(node) list;
    list_t *next = node->next;
    list_t *prev = node->prev;
    dprintf(2, "node : [%p], next: [%p], prev: [%p]\n", node, next, prev);

    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    free(node);
    if (node == list)
        return next ? next : prev;
    return list;
}

list_t *node_delete_fn(list_t *list, CHECKFN, void *data)
{
    LIST_CHECKPTR(check_fn) list;

    for (list_t *l = list, *next = list->next; l; l = next, next = l->next)
        if (check_fn(l->data, data))
            list = node_delete(list, l);

    return list;
}