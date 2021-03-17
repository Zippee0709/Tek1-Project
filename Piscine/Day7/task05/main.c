/*
** EPITECH PROJECT, 2018
** main.C
** File description:
** main with my_rev_params
*/

void my_print_params(char ac, char **av)
{
    ac = ac - 1;
    
    while (ac >= 0) {
        my_putstr(av[ac]);
        my_putchar('\n');
        ac = ac - 1;
    }
}

int main(int ac, char **av)
{
    my_print_params(ac, av);
    return (0);
}
