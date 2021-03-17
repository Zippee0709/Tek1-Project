/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_pur_nbr.c
*/

int my_putchar(char c);

int my_put_nbr(int n)
{
    int reste = 0;
    int quotient = 0;

    if(n >= 0 && n <= 9) {
        my_putchar(n + '0');
    } else if(n < 0) {
        my_putchar('-');
        n = -n;
        my_put_nbr(n);
    } else {
        quotient = n / 10;
        reste = n % 10;
        my_put_nbr(quotient);
        my_putchar(reste + 48);
    }
    return (0);
}
