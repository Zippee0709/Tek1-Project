/*
** EPITECH PROJECT, 2019
** my str to word array
** File description:
** minishell
*/

#include "my.h"

static int count_words(char const *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            count = count + 1;
        i = i + 1;
    }
    return (count + 1);
}

static char *fill_array(char const *str, int *size, char c)
{
    static int i = 0;
    int a = 0;
    char *array = malloc(sizeof(char) * (*size - i));

    while (i != *size) {
        if (str[i] == c || str[i] == '\0')
            i = i + 1;
        else {
            array[a] = str[i];
            a = a + 1;
            i = i + 1;
        }
    }
    array[a] = '\0';
    if (i == my_strlen(str) + 1) {
        *size = 0;
        i = 0;
    }
    return (array);
}

static char *malloc_array(char const *str, char c)
{
    static int i = 0;
    int size = my_strlen(str) + 1;

    while (i != size) {
        if (str[i] == c || str[i] == '\0') {
            i = i + 1;
            return (fill_array(str, &i, c));
        }
        i = i + 1;
    }
    return (NULL);
}

char **my_str_to_word_array(char const *str, char c)
{
    int count = count_words(str, c);
    char **array = malloc(sizeof(char *) * (count + 1));
    int i = 0;

    if (array == NULL)
        return (NULL);
    while (i != count) {
        array[i] = malloc_array(str, c);
        i = i + 1;
    }
    array[i] = NULL;
    return (array);
}
