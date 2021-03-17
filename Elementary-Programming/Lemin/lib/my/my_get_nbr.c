/*
** EPITECH PROJECT, 2019
** my_get_nbr.c
** File description:
** my_get_nbr.c
*/

int check_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_get_nbr(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (check_number(str[i]) == 1) {
            nb = nb * 10;
            nb = nb + (str[i] - '0');
        }
        else
            return (nb);
        i++;
    }
    return (nb);
}
