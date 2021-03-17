/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for my_hunter bootstrap
*/

#include "my_hunter.h"

void help(void)
{
    my_putstr("Description : Make a small video games based ");
    my_putstr("on the rules of Duck Hunt\n\n");
    my_putstr("Usage : ./my_hunter\n");
}

void create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    hunter_s hunter;

    window = sfRenderWindow_create(mode, "My_hunter", sfResize | sfClose, NULL);
    init_all(&hunter);
    while (sfRenderWindow_isOpen(window) == sfTrue) {
        main_run(window, &hunter);
    }
    my_print_score(&hunter);
    my_destroy(&hunter, window);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    else
        create_window();
    return (0);
}
