/*
** EPITECH PROJECT, 2019
** init_game
** File description:
** init_game
*/

#include "tetris.h"
#include "my.h"

static char **my_fill_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++)
            map[i][j] = ' ';
        map[i][j] = '\0';
    }
    map[i] = NULL;
    return (map);
}

static char **my_init_map(int x, int y)
{
    int i = 0;
    char **map = malloc(sizeof(char *) * (y + 1));

    if (map == NULL)
        return (NULL);
    for (i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        if (map[i] == NULL)
            return (NULL);
    }
    map = my_fill_map(map, x, y);
    return (map);
}

void my_init_game(game_t *game, tetris_t *tetris)
{
    game->ch = 0;
    game->status = 0;
    game->x = tetris->opt->size.y;
    game->y = tetris->opt->size.x;
    game->map = my_init_map(game->x, game->y);
    game->tmp = my_init_map(game->x, game->y);
    my_init_tab_shape(game);
    game->current = my_get_new_shape(game);
    game->next = my_get_new_shape(game);
}
