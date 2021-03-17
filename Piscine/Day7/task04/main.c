/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c for my_print_params
*/

void my_print_params(int ac, char **av)
{
    int i = 0;

    while (i != ac) {
        my_putstr(av[i]);
        my_putchar('\n');
        i = i + 1;
    }
}


int main(int ac, char **av)
{
    my_print_params(ac, av);
    return (0);
}
