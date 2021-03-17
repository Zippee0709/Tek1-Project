/*
** EPITECH PROJECT, 2019
** bombyx.h
** File description:
** bombyx.h
*/

#ifndef BOMBYX_H
#define BOMBYX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct global_t
{
    int status;
    float value;
    float mul;
    float max;
}global_t;

int my_is_num(char c);
void my_putchar_err(char c);
void my_putstr_err(char const *str);

int check_error_av1(char *av);
int check_error(int ac, char **av);

void init_global(global_t *global, int ac, char **av);
void my_bombyx(global_t *global, int ac);
#endif
