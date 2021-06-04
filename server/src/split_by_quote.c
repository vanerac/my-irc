/*
** EPITECH PROJECT, 2021
** function for split by quote
** File description:
** split_by_quote
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_param_with_quote(char *str)
{
    int total = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            total++;
    }
    return total;
}

int get_size_param(char *str, int tmp)
{
    while (str[tmp] != '\0' && str[tmp] != '\"') {
        tmp++;
    }
    return tmp;
}

char *get_param(char *str, int *index)
{
    int tmp = 0;
    int size = 0;
    char *arg = NULL;

    while (str[*index] != '"' && str[*index] != '\0') {
        *index += 1;
    }
    *index += 1;
    tmp = *index;
    size = get_size_param(str, tmp) - tmp;
    if (!(arg = malloc(sizeof(char) * (size + 1))))
        return NULL;
    arg = strncpy(arg, &str[tmp], size);
    arg[size] = '\0';
    *index += size;
    return arg;
}

char **empty_array()
{
    char **array = malloc(sizeof(char *) * 2);

    if (!array)
        return NULL;
    array[0] = strdup("");
    if (!array[0])
        return NULL;
    array[1] = NULL;
    return array;
}

char **split_by_quote(char *str)
{
    int index = 0;
    char **params = NULL;
    int nb_param = 0;
    
    if (!str)
        return NULL;
    nb_param = count_param_with_quote(str);
    if ((nb_param % 2) != 0)
        return NULL;
    // if (nb_param == 0)
        // return empty_array();
    if (!(params = malloc(sizeof(char *) * (nb_param / 2) + 1)))
        return NULL;
    for (int i = 0; i < (nb_param / 2); i++) {
        if (!(params[i] = get_param(str, &index)))
            return NULL;
        index += 1;
    }
    params[nb_param / 2] = NULL;
    return params;
}