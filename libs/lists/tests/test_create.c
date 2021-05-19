/*
** EPITECH PROJECT, 2021
** C
** File description:
** test_create.c file
*/

#include <criterion/criterion.h>
#include "list.h"

Test(list, create_list)
{
    cr_assert_neq(node_list_create(NULL), NULL);
}