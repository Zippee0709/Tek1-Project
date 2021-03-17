/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for
*/

#include "trigo.h"

void my_print_dtab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        printf("tab[i] = %s\n", tab[i]);
        i++;
    }
}

void my_display_help(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n\t./108trigo fun a0 a1 a2 ...\n\n");
        printf("DESCRIPTION\n\tfun\tfunction to be appied, among at least");
        printf(" 'EXP', 'COS', 'SIN', 'COSH' and 'SINH'\n");
        printf("\tai\tcoeficients of the matrix\n\n");
        exit(EXIT_NORMAL);
    }
}

int main(int ac, char **av)
{
    Global_t global;
    
    my_display_help(ac, av);
    my_check_error(&global, ac, av);
    my_init_global(&global, ac, av);
    my_trigo(&global);
    my_free_all(&global);
    return (0);
}
