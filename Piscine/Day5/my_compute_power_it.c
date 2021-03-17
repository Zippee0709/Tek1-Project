/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** write a iterative function that return the first argument 
   raised to the power p, where p is a second argument
*/

int my_compute_power_it(int nb, int p)
{
    int i = 1;

    if (p < 0 || p == 0)
        return (0);
    while (p != 0) {
        i = i * nb;
        p = p - 1;
    }
    return (i);
}
