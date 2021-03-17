/*
** EPITECH PROJECT, 2019
** free_tetris.c
** File description:
** free tetris
*/

#include <stdlib.h>
#include "tetris.h"

void free_tetrimino_struct(tetrimino_caract_t **caract)
{
    for (int j = 0; caract[j] != NULL; j++) {
        if (caract[j]->correct != false)
            for (int i = 0; caract[j]->forms[i] != NULL; i++)
                free(caract[j]->forms[i]);
        free(caract[j]->forms);
        free(caract[j]->name);
        free(caract[j]);
    }
    free(caract);
}

void free_tetris(tetris_t *tetris)
{
    free(tetris->opt);
    free_tetrimino_struct(tetris->tetriminos);
    free(tetris);
}
