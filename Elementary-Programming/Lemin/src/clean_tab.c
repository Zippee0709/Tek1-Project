/*
** EPITECH PROJECT, 2019
** clean_tab;c
** File description:
** clean_tab.c
*/

#include "lemin.h"
#include "my.h"

int my_check_line_is_valid(char *str)
{
    int i = 0;

    if (my_strncmp(str, "##start", 7) == 0 || my_strncmp(str, "##end", 5) == 0)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == '#' && str[i + 1] != '#')
            return (-1);
        else if (str[i] == '#' && str[i + 1] == '#' ||
                str[i] <= '0' && str[i] >= '9')
            return (-1);
        i++;
    }
    return (0);
}

char *my_clean_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '#' && str[i + 1] == '#')
            i += 2;
        else if (str[i] == '#' && str[i + 1] != '#') {
            str[i] = '\0';
            return (str);
        }
        i++;
    }
    return (str);
}

int my_get_nbr_valid_line(char **tab)
{
    int i = 0;
    int nb = 0;

    while (tab[i] != NULL) {
        if (my_check_line_is_valid(tab[i]) != -1)
            nb++;
        i++;
    }
    return (nb);
}

char **my_clean_tab(char **tab)
{
    int i = 0;
    int size = my_get_nbr_valid_line(tab);
    char **array = malloc(sizeof(char *) * (size + 1));

    if (array == NULL)
        return (NULL);
    for (int j = 0; tab[j] != NULL; j++) {
        if (my_check_line_is_valid(tab[j]) != -1) {
            array[i] = my_strdup(tab[j]);
            array[i] = my_clean_str(array[i]);
            i++;
        }
    }
    array[i] = NULL;
    my_free_dtab(tab);
    return (array);
}
