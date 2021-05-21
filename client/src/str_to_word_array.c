/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** str_to_word_array
*/

#include "client.h"

size_t count_nb_word(char *str, char split)
{
    size_t nb_word = 1;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == split) {
            nb_word++;
        }
    }
    return nb_word;
}

char **split_word(char *str, char *split, int nb_word)
{
    size_t index = 0;
    int size_word = 0;
    char *token = NULL;
    char **word_array = malloc(sizeof(char *) * (nb_word + 1));

    if (!word_array)
        return NULL;
    token = strtok(str, split);
    while (token != NULL) {
        size_word = strlen(token);
        word_array[index] = malloc(sizeof(char) * size_word + 1);
        if (!word_array[index])
            return NULL;
        word_array[index] = strncpy(word_array[index], token, size_word);
        word_array[index][size_word] = '\0';
        index++;
        token = strtok(NULL, split);
    }
    word_array[index] = NULL;
    return word_array;
}

char **str_to_word_array(char *str, char spliter_char)
{
    size_t nb_word = 0;
    char **array = NULL;
    char *spliter_string = malloc(sizeof(char) * 3);

    if (!str || !spliter_string)
        return NULL;
    spliter_string[0] = spliter_char;
    spliter_string[1] = '\n';
    spliter_string[2] = '\0';
    nb_word = count_nb_word(str, spliter_char);
    array = split_word(str, spliter_string, nb_word);
    free(spliter_string);
    return array;
}