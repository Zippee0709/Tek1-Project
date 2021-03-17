/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** print like a int but with char c
*/

void	my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while ((nb / i) >= 10)
        i = i * 10;
    while (i > 0) {
        my_putchar((nb / i) % 10 + 48);
        i = i / 10;
    }
    return (0);
}
