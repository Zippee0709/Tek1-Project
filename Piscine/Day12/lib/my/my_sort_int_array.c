/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** function that sorts an integer array in ascending order
*/

void    my_swap(int *a, int *b);

void    my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    while (i != size) {
        while (array[i] > array[size - 1]) {
            my_swap(&array[i], &array[size - 1]);
            size = size - 1;
        }
        i = i + 1;
    }
}
