/*
** EPITECH PROJECT, 2019
** display_stat.c
** File description:
** display_stat.c
*/

#include "my_rpg.h"

static char **my_convert_stat_str(stat_t stat)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * (4));

    tab[0] = convert_int_to_string(stat.level);
    tab[1] = convert_int_to_string(stat.hp);
    tab[2] = convert_int_to_string(stat.attack);
    tab[3] = convert_int_to_string(stat.defense);
    return (tab);
}

void draw_stat(window_t *window, stat_t stat)
{
    sfVector2f pos = {660, 250};
    char **tab = my_convert_stat_str(stat);
    sfText *text[4] = {NULL, NULL, NULL, NULL};
    sfVector2f size = {1.5 * (float)RES_X / 720., 1.5 * (float)RES_Y / 480.};
    
    sfRenderWindow_drawSprite(window->window, stat.bg.spr, NULL);
    for (int i = 0; i < 4; i++) {
        text[i] = create_text(tab[i], FONT, sfWhite, size);
        sfText_setPosition(text[i], pos);
        sfRenderWindow_drawText(window->window, text[i], NULL);
        pos.y += 112;
    }
    for (int i = 0; i < 4; i++) {
        sfText_destroy(text[i]);
        free(tab[i]);
    }
    free(tab);
}
