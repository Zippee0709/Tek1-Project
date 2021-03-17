/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

int main(int ac, char **av, char *envp[])
{
    return ((new_seed() | errors(envp) == FAILURE)) ? (FAILURE) : (my_rpg());
}
