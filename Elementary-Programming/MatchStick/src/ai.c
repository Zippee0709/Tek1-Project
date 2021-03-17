/*
** EPITECH PROJECT, 2019
** ai.c
** File description:
** all usefull function for ai
*/

#include "my.h"
#include "matchstick.h"

void my_count_nb_pow(int nb, s_ai *ai)
{
    int i = 2;
    int (*tab[3])(int*, s_ai*) = {pow_1, pow_2, pow_4};

    while (nb > 0) {
        i = 2;
        while (i >= 0) {
            if ((*tab[i])(&nb, ai) == 1)
                i = 0;
            i = i - 1;
        }
    }
}

void my_ai_take_stick(s_game *game, int i)
{
    void (*tab[3])(s_game*) = {take_1, take_2, take_4};
    (*tab[i])(game);
}

int my_check_even(s_game *game, s_ai *ai)
{
    int i = 0;
    int nb = 0;

    while (ai->tab[i] != '\0') {
        if (ai->tab[i] > 0 && ai->tab[i] % 2 == 1) {
            my_ai_take_stick(game, i);
            nb = nb + 1;
        }
        i = i + 1;
    }
    return (nb);
}

void my_fill_nb_even_odd(s_game *game, s_ai *ai)
{
    int i = 0;

    while (i <= game->size) {
        ai->nb = my_get_max_stick(game->map, i);
        my_count_nb_pow(ai->nb, ai);
        i = i + 1;
    }
}

int my_ai_marienbad(s_game *game)
{
    s_ai ai;

    init_ai(&ai);
    my_fill_nb_even_odd(game, &ai);
    ai.tab = init_pow_tab(&ai);
    if (my_check_even(game, &ai) == 0)
        my_check_odd(game, &ai);
    my_ai_update(game);
    my_print_game_info(game);
    return (0);
}
