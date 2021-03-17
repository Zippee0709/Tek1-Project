/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for 103cipher project
*/

#include "cipher.h"

int main(int ac, char **av)
{
    cipher_s cipher;
    
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    else if (ac == 4)
        my_cipher(av, &cipher);
    else
        return (84);
}
