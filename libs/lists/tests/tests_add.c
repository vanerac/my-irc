/*
** EPITECH PROJECT, 2021
** C
** File description:
** tests_add.c file
*/

#include "list.h"
#include <criterion/criterion.h>

extern list_t *list;

void create_list(void);

void cleanup(void);

Test(list_add, append_non_null, .init = create_list, .fini = cleanup)
{
    cr_assert(node_append_data(list, (void *) 1) == true);
}

Test(list_add, append_null, .init = create_list, .fini = cleanup)
{
    cr_assert(node_append_data(NULL, (void *) 1) == false);
}

Test(list_add, insert_non_null, .init = create_list, .fini = cleanup)
{
    cr_assert(node_insert_data(list, (void *) 1) == true);
}

Test(list_add, insert_null, .init = create_list, .fini = cleanup)
{
    cr_assert(node_insert_data(NULL, (void *) 1) == false);
}