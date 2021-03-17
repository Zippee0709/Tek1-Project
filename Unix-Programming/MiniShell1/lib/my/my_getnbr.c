/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** function that return a number sent to the function as a string.
*/

int check_number(char c)
{
    int i = 0;

    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int check_sign(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if ((str[i] == '-' ) && (check_number(str[i + 1]) == 1))
            j = 1;
        i = i + 1;
    }
    return (j);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (check_number(str[i]) == 1) {
            nb = nb * 10;
            nb = nb + (str[i] - '0');
            i = i + 1;
        }
        else
            return (-1);
    }
    return (nb);
}
