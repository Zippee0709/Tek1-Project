/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** check my str if all char is alpha
*/

int my_check_all_letter(char c)
{
    if (c >= 97 && c <= 122 || c >= 65 && c <= 90)
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;
    int status = 1;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            status = 1;
        else if (my_check_all_letter(str[i]) == 1)
            status = 1;
        else {
            status = 0;
            return (status);
        }
        i = i + 1;
    }
    return (status);
}
