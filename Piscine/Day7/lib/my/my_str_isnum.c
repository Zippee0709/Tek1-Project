/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** check my str if all char is digits
*/

int my_check_digit(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;
    int status = 1;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            status = 1;
        else if (my_check_digit(str[i]) == 1)
            status = 1;
        else {
            status = 0;
            return (status);
        }
        i = i + 1;
    }
    return (status);
}
