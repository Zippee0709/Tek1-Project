/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int check_sign(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (((str[i] == '-') && str[i + 1] == '+') ||
            ((str[i] == '+') && str[i + 1] == '-')) {
            return (-1);
        }
        if (((str[i] == '-') && (str[i + 1] == '-')) || (str[i] == '+')) {
            return (1);
        }
        if (str[i] == '-') {
            return (-1);
        } else {
            return (1);
        }
        i = i + 1;
    }
    return (1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - 48;
        }
        i = i + 1;
    }
    nbr = nbr * check_sign(str);
    return (nbr);
}
