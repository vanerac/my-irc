/*
** EPITECH PROJECT, 2021
** C
** File description:
** test_find.c file
*/


#include <criterion/criterion.h>
#include "list.h"

extern list_t *list;

void create_list(void);

void cleanup(void);

static bool find_fn(void *iterator, void *args)
{
    return iterator == args;
}

Test(list_find, find_data, .init = create_list, .fini = cleanup)
{
    int val = 2;
    node_append_data(list, &val);
    list_t *found = node_find_data(list, &val);

    cr_assert(found != NULL);
    cr_assert(found->data == &val);
}

Test(list_find, find_fn, .init = create_list, .fini = cleanup)
{
    int val = 2;
    node_append_data(list, &val);
    list_t *found = node_find_fn(list, &find_fn, &val);
    cr_assert(found != NULL);
    cr_assert(found->data == &val);
}

Test(list_find, find_fn_failed, .init = create_list, .fini = cleanup)
{
    int val = 2;
    list_t *found = node_find_fn(list, &find_fn, &val);
    cr_assert(found == NULL);
}

Test(list_find, find_data_failed, .init = create_list, .fini = cleanup)
{
    int val = 1;
    cr_assert(node_find_data(list, &val) == NULL);
}