/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** transform all 1 char on everyword into maj
*/

#include "my.h"

int my_check_sign(char c)
{
    if (c >= 32 && c <= 47 || c >= 58 && c <= 64 )
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int status = 0;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if (status == 0 && my_check_letter_min(str[i]) == 1) {
            str[i] = str[i] - 32;
            status = 1;
        }
        else if (my_check_sign(str[i]) == 1)
            status = 0;
        else
            status = 1;
        i = i + 1;
    }
    return (str);
}
