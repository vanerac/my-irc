/*
** EPITECH PROJECT, 2021
** C
** File description:
** test_find.c file
*/


#include <criterion/criterion.h>
#include "list.h"

extern list_t *list;

void create_list();

void cleanup();

Test(list_find, find_data, .init=create_list, .fini=cleanup)
{
}

Test(list_find, find_fn, .init=create_list, .fini=cleanup)
{
}

Test(list_find, find_fn_failed, .init=create_list, .fini=cleanup)
{
}

Test(list_find, find_data_failed, .init=create_list, .fini=cleanup)
{
}


