/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy_resources.c
*/

#include "my_rpg.h"

void clean_pointers(rpg_t *rpg)
{
    free(rpg->inv);
    free(rpg->map);
    free(rpg);
}

void clean_sprites(rpg_t *rpg)
{
    sfSprite_destroy(rpg->cursor.pointer);
    sfSprite_destroy(rpg->inv->sprite);
    sfTexture_destroy(rpg->cursor.texture);
    sfTexture_destroy(rpg->inv->txture);
    for (int a = 0; rpg->map[a] != NULL; a++)
        for (int b = 0; rpg->map[a][b].tile != NULL; b++) {
            sfSprite_destroy(rpg->map[a][b].tile);
            sfTexture_destroy(rpg->map[a][b].txture);
        }
    for (int a = 0; a != 5; a++) {
        sfTexture_destroy(rpg->pause[a].tex);
        sfSprite_destroy(rpg->pause[a].spr);
    }
}

void clean_window(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->screen.window);
    sfView_destroy(rpg->screen.view);
}

int destroy_resources(rpg_t *rpg)
{
    clean_window(rpg);
    clean_sprites(rpg);
    clean_pointers(rpg);
    sfVertexArray_clear(rpg->cursor.trail);
    sfVertexArray_clear(rpg->cursor.shape);
    sfVertexArray_destroy(rpg->cursor.trail);
    sfVertexArray_destroy(rpg->cursor.shape);
    return (SUCCESS);
}
