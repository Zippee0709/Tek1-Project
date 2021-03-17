/*
** EPITECH PROJECT, 2019
** game_check.c
** File description:
** game_check.c
*/

#include "my_defender.h"

int check_rect_of_two_pos(sfVector2f s_pos, sfVector2f m_pos, s_game *game)
{
    sfFloatRect a;
    sfFloatRect b;
    sfVector2f s_max = (sfVector2f){s_pos.x + 30, s_pos.y + 30};
    sfVector2f m_max = (sfVector2f){m_pos.x + 80, m_pos.y + 60};
    init_float_rect(&a, s_pos, s_max);
    init_float_rect(&b, m_pos, m_max);

    if (a.left >= b.left && a.top >= b.top &&
        a.width <= b.width && a.height <= b.height) {
        game->shots = pop_begin_dlist(game->shots);
        return (1);
    }
    return (0);
}

int check_shots_on_enemies(s_game *game)
{
    Dlist_node *shots;
    Dlist_node *monster;

    if (game->shots == NULL || game->enemies == NULL)
        return (0);
    shots = game->shots->begin;
    monster = game->enemies->begin;
    while (shots != NULL && monster->obj.pos.x > 100 && monster->obj.pos.y > 50) {
        if (check_rect_of_two_pos(shots->obj.pos, monster->obj.pos, game) == 1) {
            monster->obj.stat.life -= 1;
        }
        shots = shots->next;
    }
    return (0);
}

int check_life_on_enemies(Dlist *enemies)
{
    Dlist_node *tmp = enemies->begin;

    while (tmp != NULL) {
        if (tmp->obj.stat.life <= 0) {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void init_text_again(s_game *game)
{
    sfVector2f score = {1600, 50};
    char *str_life = my_int_convert_str(game->castle_life);

    sfText_setString(game->text.castle,"Castle : ");
    sfText_setString(game->text.castle_life, str_life);
    sfText_setFont(game->text.castle, game->font);
    sfText_setFont(game->text.castle_life, game->font);
    sfText_setCharacterSize(game->text.castle, 30);
    sfText_setCharacterSize(game->text.castle_life, 30);
    sfText_setPosition(game->text.castle, score);
    score.x = score.x + 160;
    sfText_setPosition(game->text.castle_life, score);
    sfText_setColor(game->text.castle, sfMagenta);
    sfText_setColor(game->text.castle_life, sfMagenta);
    free(str_life);
}

s_stat init_stat_tower(float value)
{
    s_stat stat;

    stat.life = value;
    stat.armor = value;
    stat.power = value;
    stat.speed = value;
    return (stat);
}
