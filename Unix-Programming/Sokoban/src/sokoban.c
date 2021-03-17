/*
** EPITECH PROJECT, 2018
** sokoban.c
** File description:
** 
*/

#include "my.h"
#include "sokoban.h"

void help(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE : ./my_sokoban map\n");
        my_putstr("DESCRIPTION :\n");
        my_putstr("Map : file representing the warehouse map, ");
        my_putstr("containing `#' for walls, `P' for the player, ");
        my_putstr("`X' for boxes and `O' for storage locations.\n");
        exit(0);
    }
}

void init_vector(vector2i *v)
{
    v->x = -1;
    v->y = -1;
}

void init_sokoban(sokoban_s *sokoban, char const *av)
{
    sokoban->size = get_size_with_stat(av);
    sokoban->map_s = read_file(av, sokoban->size);
    my_check_map(sokoban->map_s);
    sokoban->status = -1;
    sokoban->nb_x = my_count_x(sokoban->map_s);
    sokoban->map = my_str_to_word_tab(sokoban->map_s);
    sokoban->map_copy = my_str_to_word_tab(sokoban->map_s);
    init_vector(&sokoban->v_o);
    free(sokoban->map_s);
}

void my_sokoban(char **av, sokoban_s *sokoban)
{
    init_sokoban(sokoban, av[1]);
    my_game(sokoban);
    my_free_word_tab(sokoban->map);
    my_free_word_tab(sokoban->map_copy);
}
