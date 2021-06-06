/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** tools
*/

#include "client.h"

int get_array_size(char **array)
{
    int size = 0;

    if (!array)
        return 0;
    while (array[size] != NULL) {
        size += 1;
    }
    return size;
}

void free_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}