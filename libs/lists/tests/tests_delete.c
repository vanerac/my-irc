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

Test(list_delete, last_node, .init = create_list, .fini = cleanup)
{
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    node_append_data(list, &data1);
    node_append_data(list, &data2);
    node_append_data(list, &data3);

    list = node_delete_data(list, &data3);
    cr_assert(node_find_data(list, &data1) != NULL);
    cr_assert(node_find_data(list, &data2) != NULL);
    cr_assert(node_find_data(list, &data3) == NULL);
}

Test(list_delete, first_node, .init = create_list, .fini = cleanup)
{
    int data1 = 1;
    int data2 = 2;
    node_append_data(list, &data1);
    node_append_data(list, &data2);

    list_t *second = node_find_data(list, &data1);
    list = node_delete(list, list);
    cr_assert(list != NULL);
    cr_assert(list = second);
}

Test(list_delete, middle_node, .init = create_list, .fini = cleanup)
{
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    node_append_data(list, &data1);
    node_append_data(list, &data2);
    node_append_data(list, &data3);

    list = node_delete_data(list, &data2);
    cr_assert(node_find_data(list, &data1) != NULL);
    cr_assert(node_find_data(list, &data2) == NULL);
    cr_assert(node_find_data(list, &data3) != NULL);
}

Test(list_delete, only_node, .init = create_list, .fini = cleanup)
{
    list = node_delete(list, list);
    cr_assert(list == NULL);
}