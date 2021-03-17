/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** affiche une string
*/

#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void put_str_err(char *cmd, char *error)
{
    write(2, cmd, my_strlen(cmd));
    write(2, error, my_strlen(error));
}