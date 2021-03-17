/*
** EPITECH PROJECT, 2019
** trigo.h
** File description:
** trigo.h
*/

#ifndef TRIGO_H
#define TRIGO_H

#define EXIT_NORMAL (0)
#define EXIT_FAIL   (84)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

typedef struct Global_t
{
    char **tab_type;
    char *type;
    float *value;
    float *result;
    float length;
    int size;
}Global_t;

typedef void (*tpsf)(Global_t *);

void my_putstr_err(char *str);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
void my_print_dtab(char **tab);

void my_init_global(Global_t *global, int ac, char **av);
void my_check_error(Global_t *global, int ac, char **av);
char *my_malloc_msg(char *str);
char **my_malloc_dtab_type(void);
void my_trigo(Global_t *global);

int equal_mat(float *dest, float *src, int length);
void copy_mat(float *dest, float *src, int length);
int empty_mat(float *tab, int length);

float *fill_basic_info(int size, int length);
void display_float_tab(float *tab, int size);

void my_exp(Global_t *global);
void my_cos(Global_t *global);
void my_sin(Global_t *global);
void my_cosh(Global_t *global);
void my_sinh(Global_t *global);
int can_leave(Global_t *global, float *current);

int empty_mat(float *tab, int length);
int equal_mat(float *dest, float *src, int length);
void copy_mat(float *dest, float *src, int length);

float *add_mat(float *src, float *obj, int length);
float *sub_mat(float *src, float *obj, int length);
float *multi_mat(float *src, float *obj, int length, int size);
float *div_mat(float *src, float k, int length, int size);

void my_free_all(Global_t *global);
void my_free_dtab(char **tab);

#endif
