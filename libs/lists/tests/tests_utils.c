/*
** EPITECH PROJECT, 2021
** C
** File description:
** tests_utils.c file
*/

#include "list.h"

list_t *list;

void create_list(void)
{
    list = node_list_create((void *) 1);
}

void cleanup(void)
{
    for (list_t *prev = NULL; list; prev = list, list = list->next, free
    (prev));
}