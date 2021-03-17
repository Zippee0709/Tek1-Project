/*
** EPITECH PROJECT, 2018
** my_intlen
** File description:
** my_intlen
*/

int my_intlen(int nbr)
{
    int len = 0;

    while (nbr != 0) {
        nbr = nbr / 10;
        len = len + 1;
    }
    return (len);
}
