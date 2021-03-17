/*
** EPITECH PROJECT, 2019
** count_occur.c
** File description:
** count occurence
*/

#include "tetris.h"

int count_occur(char *str, char occur)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == occur) {
            counter++;
        }
    }
    return (counter);
}
