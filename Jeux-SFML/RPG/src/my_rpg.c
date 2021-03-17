/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg.c
*/

#include "my_rpg.h"

int my_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(*rpg));
    menu_t menu;
    sprite_t pnj;

    if (load_all(rpg, &menu, &pnj))
        return (FAILURE);
    while (sfRenderWindow_isOpen(rpg->screen.window)) {
        cursor_position(rpg->screen.window, &rpg->cursor, rpg->screen.offset);
        manage_events(rpg, &menu);
        update_snow(rpg->snow, rpg->screen.offset);
        draw_sprites(rpg, &menu, &pnj);
        pnj_event(rpg, &pnj);
        cursor_move_on_menu(&rpg->cursor, &menu);
        player_global_intersect(rpg);
        update_stat_menu_status(rpg, rpg->player.stat);
    }
    return (destroy_resources(rpg));
}
