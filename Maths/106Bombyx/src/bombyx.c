/*
** EPITECH PROJECT, 2019
** bombyx.c
** File description:
** bombyx.c
*/

#include "bombyx.h"

void my_basic_gen(global_t *global)
{
    int i = 1;
    float x = global->value;

    while (i <= 100) {
        printf("%d %.2f\n", i, x);
        x = global->mul * x * (1000 - x)/1000;
        i++;
    }
}

float my_gen_step(global_t *global, float k, float x)
{
    float i = 1;

    while (i <= global->max) {
        while (i < global->mul) {
            x = k * x * (1000 - x)/1000;
            i++;
        }
        x = k * x * (1000 - x)/1000;
        printf("%.2f %.2f\n", k, x);
        i++;
    }
    return (x);
}

void my_advance_gen(global_t *global)
{
    float k = 1;
    float x = global->value;

    while (k <= 4) {
        x = my_gen_step(global, k, x);
        k = k + 0.01;
    }
}

void my_bombyx(global_t *global, int ac)
{
    if (ac == 3)
        my_basic_gen(global);
    else if (ac == 4)
        my_advance_gen(global);
}
