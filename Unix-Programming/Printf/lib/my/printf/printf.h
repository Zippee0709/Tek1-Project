/*
** EPITECH PROJECT, 2018
** printf.h
** File description:
** printf.h
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

typedef struct format_s
{
    int field;
    int precision;
    int nb_digit;
    char sign;
}format_s;

typedef void (*tpsf)(va_list, format_s *);

void flag_d(va_list av, format_s *format);
void flag_o(va_list av, format_s *format);
void flag_u(va_list av, format_s *format);
void flag_x(va_list av, format_s *format);
void flag_X(va_list av, format_s *format);
void flag_c(va_list av, format_s *format);
void flag_s(va_list av, format_s *format);
void flag_S(va_list av, format_s *format);
void flag_p(va_list av, format_s *format);
void flag_b(va_list av, format_s *format);
void flag_mod(va_list av, format_s *format);

char *my_put_nbr_base(int nb, char *base);
void my_put_nbr_base_s(int nb, char *base);
int my_put_unsigned_nbr(unsigned nb);
int my_put_unsigned_nbr_base(unsigned nb, char *base);

void check_format(char *str, int *nb, format_s *format);
void my_format_print(format_s *format);

int my_get_nbdigit(int nb);
#endif
