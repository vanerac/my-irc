/*
** EPITECH PROJECT, 2021
** C
** File description:
** list_delete.c file
*/

#include "list.h"

void node_delete_data(list_t *list, void *data)
{
    LIST_CHECKPTR(data);
    list_t *ptr = list;
    for (; ptr && ptr->data != data; ptr = ptr->next);
    node_delete(ptr);

}

void node_delete(list_t *node)
{
    LIST_CHECKPTR(node);
    list_t *next = node->next;
    list_t *prev = node->prev;

    if (prev)
        prev->next = next;
    free(node);
}

void node_delete_fn(list_t *list, CHECKFN, void *data)
{
    LIST_CHECKPTR(check_fn);
    bool iterate = true;

    for (list_t *l = list; l; l = iterate ? l->next : l)
        if (check_fn(l->data, data)) {
            node_delete(l);
            iterate = !iterate;
        } else
            iterate = true;
}