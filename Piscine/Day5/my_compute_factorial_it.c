/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it.c
** File description:
** write an iterative function that return the 
   factorial of the numer given as parameter
*/
int my_compute_factorial_it(int nb)
{
    int i = nb;

    if (nb < 0 || nb > 12)
        return (0);
    else if (nb <= 1)
        return (1);
    while (i > 1) {
        nb = nb * (i - 1);
        i = i - 1;
    }
    return (nb);
}
