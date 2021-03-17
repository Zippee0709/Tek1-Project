/*
** EPITECH PROJECT, 2018
** infinadd.h
** File description:
** infinadd.h
*/

#ifndef INFINADD_H
#define INFINADD_H

typedef struct infin
{
    char *s1;
    char *s2;
    int size1;
    int size2;
    char *res;
    int neg;
}infin_t;

int cti(char c);
char itc(int c);
int my_check_negative(char *s1, char *s2);
void my_check_lenght(infin_t *infin);
void my_call_func(infin_t *infin);
int my_who_is_neg(char *str);
int my_check_size(char *str);

void my_put_retenu(infin_t *infin, int *j, int *retenu);
void my_put_neg(infin_t *infin, int *j);
void my_putstr_infinadd(char *str);
char *my_put_sup_neg(char *res);

void my_print_sup_res(char *str);

int init_infin(infin_t *infin, char **av);
int my_res(char s1, char s2, int i, int l);
char my_add(char s1, char s2, int *retenu, int i, int l);
void infinadd(char *s1, char *s2, infin_t *infin);
void infinsub(char *s1, char *s2, infin_t *infin);
#endif
