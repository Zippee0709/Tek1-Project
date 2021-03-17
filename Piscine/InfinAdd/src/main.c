/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for infin_add
*/

#include "my.h"
#include "infinadd.h"

int main(int ac, char **av)
{
    infin_t infin;

    if (ac != 3) {
        my_putstr_err("Invalid argument !\n");
        return (84);
    }
    init_infin(&infin, av);
    return (0);
}
