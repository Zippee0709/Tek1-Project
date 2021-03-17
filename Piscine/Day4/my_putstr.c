/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** function who  display all character of a stirng 
*/

void    my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}
