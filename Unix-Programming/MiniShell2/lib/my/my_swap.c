/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** function who swap content of two integers
*/

void    my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
