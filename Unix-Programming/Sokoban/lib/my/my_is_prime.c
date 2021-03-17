/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** write a function that return 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    if (nb < 0)
        return (0);
    if (nb % 2 == 0)
        return (1);
    return (0);
}
