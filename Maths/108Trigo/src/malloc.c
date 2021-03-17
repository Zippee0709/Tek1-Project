/*
** EPITECH PROJECT, 2019
** malloc.c
** File description:
** malloc.c
*/

#include "trigo.h"

char *my_malloc_msg(char *str)
{
    int i = 0;
    int size = my_strlen(str);
    char *msg = malloc(sizeof(char) * (size + 1));

    if (msg == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        exit(EXIT_FAIL);
    }
    while (str[i] != '\0') {
        msg[i] = str[i];
        i++;
    }
    msg[i] = '\0';
    return (msg);
}

char **my_malloc_dtab_type(void)
{
    char **tab = malloc(sizeof(char *) * (5 + 1));

    if (tab == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        exit(EXIT_FAIL);
    }
    tab[0] = my_malloc_msg("EXP");
    tab[1] = my_malloc_msg("COS");
    tab[2] = my_malloc_msg("SIN");
    tab[3] = my_malloc_msg("COSH");
    tab[4] = my_malloc_msg("SINH");
    tab[5] = NULL;
    return (tab);
}
