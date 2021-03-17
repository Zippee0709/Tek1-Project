/*
** EPITECH PROJECT, 2018
** printf.h
** File description:
** printf.h
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

void flag_d(va_list av);
void flag_o(va_list av);
void flag_u(va_list av);
void flag_x(va_list av);
void flag_X(va_list av);
void flag_c(va_list av);
void flag_s(va_list av);
void flag_S(va_list av);
void flag_p(va_list av);
void flag_b(va_list av);
void flag_mod(va_list av);

int my_put_nbr_base(int nb, char *base);
int my_put_unsigned_nbr(unsigned nb);
int my_put_unsigned_nbr_base(unsigned nb, char *base);

#endif
