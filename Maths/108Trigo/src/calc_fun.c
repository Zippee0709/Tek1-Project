/*
** EPITECH PROJECT, 2019
** calc_fun.c
** File description:
** calc_fun.c
*/

#include "trigo.h"

void my_exp(Global_t *global)
{
    float *array = malloc(sizeof(float) * global->length);
    float *tmp = malloc(sizeof(float) * global->length);
    float *current = malloc(sizeof(float) * global->length);
    int fac = 1;
    int i = 2;
    
    if (array == NULL || tmp == NULL || current == NULL)
        return;
    global->result = fill_basic_info(global->size, global->length);
    copy_mat(array, global->value, global->length);
    global->result = add_mat(global->result, global->value, global->length);

    while (i < 200) {
        copy_mat(current, global->result, global->length);
        array = multi_mat(array, global->value, global->length, global->size);
        fac *= i;
        copy_mat(tmp, array, global->length);
        tmp = div_mat(tmp, fac, global->length, global->size);
        global->result = add_mat(global->result, tmp, global->length);
        display_float_tab(global->result, global->size);
        free(tmp);
        if (can_leave(global, current))
            break;
        i++;
    }
    free(array);
    free(current);
}

void my_cos(Global_t *global)
{

}

void my_sin(Global_t *global)
{

}

void my_cosh(Global_t *global)
{

}

void my_sinh(Global_t *global)
{

}
