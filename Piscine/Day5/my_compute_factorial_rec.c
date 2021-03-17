/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** write a recursive function that returns 
   the factorial of th enumber given as a parameter
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 13)
        return (1);
    if (nb == 1)
    	return (nb);
    return (nb * my_compute_factorial_rec(nb - 1));
}
