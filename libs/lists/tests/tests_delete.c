/*
** EPITECH PROJECT, 2021
** C
** File description:
** test_delete.c file
*/

#include <criterion/criterion.h>
#include "list.h"

extern list_t *list;

void create_list();
void cleanup();

Test(list_delete, last_node, .init=create_list, .fini=cleanup)
{
    list_t *list = node_list_create((void *) 1);
    node_append_data(list, (void *) 1);
}

//Test(list_delete, first_node, .init=create_list, .fini=cleanup)
//{
//}
//
//Test(list_delete, middle_node, .init=create_list, .fini=cleanup)
//{
//}
//
//Test(list_delete, only_node, .init=create_list, .fini=cleanup)
//{
//}