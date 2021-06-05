/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** tools
*/

#include "client.h"

int array_size(char **array)
{
    int inc;

    for (inc = 0; array[inc] != NULL; inc++) {};
    return (inc);
}

void free_table(char **table)
{
    for (int i = 0; i < array_size(table); i++)
        free(table[i]);
    free(table);
}