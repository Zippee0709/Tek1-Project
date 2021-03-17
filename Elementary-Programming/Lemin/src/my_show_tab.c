/*
** EPITECH PROJECT, 2019
** my_show_tab.c
** File description:
** my_show_tab.c
*/

#include "lemin.h"
#include "my.h"

void my_show_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

void my_show_int_dtab(int **tab)
{
    int i = 0;
    int j = 0;

    my_put_nbr(tab[i][j]);
    my_put_nbr(tab[i][1]);
    my_putchar('\n');
    for (i = 0; tab[i] != NULL; i++) {
        for (j = 0; tab[i][j] != '\0'; j++) {
            my_put_nbr(tab[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void my_show_file(char **tab)
{
    int status = 0;

    my_putstr("#number_of_ants\n");
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        if (i == 0) {
            my_putstr("\n#rooms");
            status = 1;
        }
        else if (tab[i + 1] != NULL && status == 1 &&
                my_check_str_is_tunnel(tab[i + 1]) == 0) {
            my_putstr("\n#tunnels");
            status++;
        }
        my_putchar('\n');
    }
    my_putstr("#moves\n");
}
