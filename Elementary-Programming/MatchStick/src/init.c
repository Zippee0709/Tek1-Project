/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** all usefull function for init game
*/

#include "my.h"
#include "matchstick.h"

char **init_map(int size, int length)
{
    int i = 0;
    char **map = malloc(sizeof(char *) * (size + 1 + 2));

    if (map == NULL) {
        my_putstr_err("Error : Allocation memory failed !\n");
        return (NULL);
    }
    while (i < size + 2) {
        map[i] = malloc(sizeof(char) * (length + 1));
        if (map[i] == NULL) {
            my_putstr_err("Error : Allocation memory failed !\n");
            return (NULL);
        }
        i = i + 1;
    }
    return (map);
}

int init_game(s_game *game, char **av)
{
    game->size = my_getnbr(av[1]);
    if (my_line_error(game->size) == -1)
        return (84);
    game->length = game->size * 2 + 1;
    game->nb_stick = my_getnbr(av[2]);
    if (my_stick_error(game->nb_stick, game->size) == -1)
        return (84);
    else if ((game->map = init_map(game->size, game->length)) == NULL)
        return (84);
    my_fill_tab(game);
    game->evt = PLAYER;
    game->user_line = 0;
    game->user_stick = 0;
    game->ai_line = 0;
    game->ai_stick = 0;
    return (0);
}

int init_ai(s_ai *ai)
{
    ai->nb = 0;
    ai->pow = 2;
    ai->pow_1 = 0;
    ai->pow_2 = 0;
    ai->pow_4 = 0;
    return (0);
}

int *init_pow_tab(s_ai *ai)
{
    int *tab = malloc(sizeof(int) * (3 + 1));

    if (ai->tab == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        return (NULL);
    }
    tab[0] = ai->pow_1;
    tab[1] = ai->pow_2;
    tab[2] = ai->pow_4;
    tab[3] = '\0';
    return (tab);
}
