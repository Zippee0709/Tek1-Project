/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for
*/

#include "dante.h"

int my_calc_wall_to_break(int x, int y)
{
    int result = (x * y);

    if (result <= 10)
        return (1);
    else if (result <= 25)
        return (result / 4);
    return (result / 10);
}

int my_execute_generator(int ac, char **av)
{
    Dante_t dante;
    int wall = 0;

    if (my_init_dante(&dante, ac, av) == 84)
        return (84);
    my_gen_perfect_map(&dante);
    if (dante.type == IMPERFECT) {
        wall = my_calc_wall_to_break(dante.pos.max_x, dante.pos.max_y);
        my_gen_imperfect_map(dante.map, &dante.pos, wall);
    }
    my_print_map(dante.map, dante.pos);
    my_free_dlist(dante.list);
    my_free_map(dante.map, dante.pos);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4) {
        printf("Error : bad argv !\n");
        return (84);
    }
    if (my_execute_generator(ac, av) == 84)
        return (84);
    return (0);
}
