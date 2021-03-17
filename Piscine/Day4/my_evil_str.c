/*
** EPITECH PROJECT, 2018
** my_evil_str.c
** File description:
** function who swp each of the string's character 2 by 2
*/

void    my_putchar(char c);
int my_strlen(char const *str);

void    *my_evil_str(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c = 'a';

    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
