/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init.c
*/

#include "my_rpg.h"

static int create_player(sprite_t *player)
{
    sfVector2f scale = {720, 480};

    init_fctptr(player);
    player->sprite = player->create_sprite(&player->texture, PLAYER, scale);
    if (!player->sprite)
        return (FAILURE);
    player->rect = player->create_rect(0, 0, 32, 32);
    player->vector = player->create_vector(310., 150., scale);
    player->clock = sfClock_create();
    player->move = -1;
    player->stat = init_stat(100, 100, 5, 5);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->vector);
    return (SUCCESS);
}

static int load_window(rpg_t *rpg, window_t *screen, sprite_t *mist)
{
    screen->offset = (sfVector2f){0.0, 0.0};
    screen->window = create_window(false, "MY_RPG");
    screen->view = sfView_createFromRect((sfFloatRect){0, 0, RES_X, RES_Y});
    screen->draw = sfRenderWindow_drawSprite;
    if (!screen->window || !screen->view)
        return (FAILURE);
    sfRenderWindow_setView(screen->window, screen->view);
    create_transition(mist);
    return (SUCCESS);
}

static int init_rpg_variables(rpg_t *rpg)
{
    rpg->cursor = init_cursor(rpg->screen.window);
    rpg->map = load_maps();
    rpg->coll = create_proto(COLL, open_file(COLL));
    if (!rpg->cursor.trail || !rpg->map || !rpg->coll)
        return (FAILURE);
    rpg->max = get_sizemap(rpg->coll);
    rpg->index = MENU;
    rpg->inv = init_inventory();
    rpg->pause = load_objects(rpg->pause, 5, PAUSE_PATH, PAUSE_POS);
    if (!rpg->pause || !rpg->inv)
        return (FAILURE);
    if (load_quest(rpg) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int load_all(rpg_t *rpg, menu_t *menu, sprite_t *pnj)
{
    sfVector2f scale = {1920., 1080.};

    if ((load_window(rpg, &rpg->screen, &rpg->mist) | load_menu(menu))
        == FAILURE || (init_rpg_variables(rpg) | create_player(&rpg->player))
        == FAILURE)
        return (FAILURE);
    rpg->snow = create_particules();
    if (create_dial(rpg, 0, 1900, 25) || create_enemies(&rpg->enemies) ||
        load_stat_menu(rpg) || create_pnj(pnj, 0, 1950, 200) || !rpg->snow)
        return (FAILURE);
    rpg->htp.spr = create_sprite(&rpg->htp.tex, HTPL, scale);
    rpg->shot_display = false;
    rpg->shot = malloc(sizeof(sfVertex) * (2));
    if (!rpg->shot)
        return (FAILURE);
    rpg->shot[0] = (sfVertex){(sfVector2f){0., 0.}, sfBlue, (sfVector2f){0.0, 0.0}};
    rpg->shot[1] = (sfVertex){(sfVector2f){0., 0.}, sfRed, (sfVector2f){0.0, 0.0}};
    return (SUCCESS);
}
