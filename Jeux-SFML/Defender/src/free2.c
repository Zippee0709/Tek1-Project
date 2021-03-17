/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "my_defender.h"

void my_free_double_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab[i]);
    free(tab);
}

void my_free_music(s_game *game)
{
    sfMusic_destroy(game->music.game);
    sfMusic_destroy(game->music.start);
    sfMusic_destroy(game->music.tower);
    sfMusic_destroy(game->music.fire);
    sfMusic_destroy(game->music.arrow);
    sfMusic_destroy(game->music.rock);
    sfMusic_destroy(game->music.ninja);
    sfMusic_destroy(game->music.game_over);
}

void my_free_clock(s_game *game)
{
    sfClock_destroy(game->clock);
    sfClock_destroy(game->clock_text);
    sfClock_destroy(game->clock_monster);
}

void my_free_dlist(Dlist *list)
{
    while (list != NULL)
        list = pop_back_dlist(list);
}
