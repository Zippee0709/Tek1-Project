/*
** EPITECH PROJECT, 2018
** str is alpha
** File description:
** is alpha ?
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
            if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
                return (0);
    return (1);
}
