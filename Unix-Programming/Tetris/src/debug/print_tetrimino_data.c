/*
** EPITECH PROJECT, 2019
** print_tetrimino_data.c
** File description:
** print tetriminos_data info
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

void swap_element(tetrimino_caract_t **caract, int min, int j)
{
    tetrimino_caract_t *tempo = caract[min];

    caract[min] = caract[j];
    caract[j] = tempo;
}

int sort_table(tetrimino_caract_t **caract)
{
    int min = 0;

    for (int i = 0; caract[i + 1] != NULL; i++) {
        min = i;
        for (int j = i + 1; caract[j] != NULL; j++) {
            if (my_strcmp_no_cs(caract[j]->name, caract[min]->name) < 0)
                min = j;
        }
        if (min != i)
            swap_element(caract, min, i);
    }
    return 0;
}

void print_tetrimino_data(tetrimino_caract_t *caract)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(caract->name);
    my_putstr(" : Size ");
    my_put_nbr(caract->size_x);
    my_putstr(" * ");
    my_put_nbr(caract->size_y);
    my_putstr(" :  Color ");
    my_put_nbr(caract->color);
    my_putstr(" :\n");
    for (int i = 0; caract->forms[i] != NULL; i++) {
        my_putstr(caract->forms[i]);
        my_putchar('\n');
    }
}

void print_tetrimino_error(tetrimino_caract_t *caract)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(caract->name);
    my_putstr(" : Error\n");
}

void print_debug(tetrimino_caract_t **caract)
{
    int counter = 0;

    sort_table(caract);
    for (int i = 0; caract[i] != NULL; i++) {
            counter++;
    }
    my_putstr("Tetriminos : ");
    my_put_nbr(counter);
    my_putchar('\n');
    for (int i = 0; caract[i] != NULL; i++) {
        if (caract[i]->correct == true)
            print_tetrimino_data(caract[i]);
        else
            print_tetrimino_error(caract[i]);
    }
}
