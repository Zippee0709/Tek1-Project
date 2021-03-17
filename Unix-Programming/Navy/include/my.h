/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Contient les prototypages de libmy.a
*/

#ifndef MY
#define MY

char **my_parser(char *str, char *separator);
void free_parse(char **parse);
int my_putchar(char c);
int my_putchar_fd(int fd, char const c);
int my_put_nbr(int nb);
int my_intlen(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_fd(int fd, char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char *str, char *str2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str);
int my_strncmp(char *str, char *str2, int n);
char *my_itoa(int nbr);

#endif
