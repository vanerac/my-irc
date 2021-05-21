/*
** EPITECH PROJECT, 2021
** C
** File description:
** test_create.c file
*/

#include <criterion/criterion.h>
#include "list.h"

extern  list_t *list;

void create_list();
void cleanup();

Test(list_create, success, .init=create_list, .fini=cleanup)
{
    cr_assert_neq(list, NULL);
}

Test(list_create, invalid_arg, .init=create_list, .fini=cleanup)
{
    cr_assert_eq(node_list_create(NULL), NULL);
}