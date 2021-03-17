/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display nb param
*/

void my_putchar(char c);

int neg(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    return (nb);
}

int div(int nb)
{
    int pow = 1;
    while (nb >= 100) {
        nb = nb / 10;
        pow = pow * 10;
    }
    return (pow);
}

int first(int nb)
{
    while (nb >= 10) {
        nb = nb / 10;
    }
    return (nb);
}

int count_digit(int nb)
{
    int dig = 0;
    while (nb > 0) {
        nb = nb / 10;
        dig++;
    }
    return (dig);
}

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
