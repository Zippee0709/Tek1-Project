/*
** EPITECH PROJECT, 2018
** rush3.h
** File description:
** rush3.h
*/

#ifndef RUSH3_H
#define RUSH3_H
#define BUFF_SIZE (4096)

#include <unistd.h>

int rush3(char *str);

void my_putchar(char c);
void my_putchar_err(char c);
void my_putstr(char const *str);
void my_putstr_err(char const *str);

int my_check_char_if_b(char *str);
int my_put_nbr(int nb);
int my_check_char_ifnot_good(char *str);

int only_one_line(char *str);
int multiple_line(char *str, int x, int y, int i);
int call_func(char *str, int x, int y, int i);

void my_print(int x, int y);
void my_check_rush1(char *str, int x, int y);
void my_check_rush2(char *str, int x, int y);
void my_check_rush3(char *str, int x, int y);
void my_check_rush4(char *str, int x, int y, int i);
void my_check_rush5(char *str, int x, int y, int i);

#endif
