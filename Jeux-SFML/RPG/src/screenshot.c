/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** screenshot.c
*/

#include "my_rpg.h"

int screen_shot(const sfRenderWindow *window)
{
    sfVector2u size = {0, 0};
    sfTexture *screen = NULL;
    sfImage *shot = NULL;
    static char name[41] = "ressources/screen-shot/SCREEN-SHOT_00.png";

    if ((name[35] & name[36]) != '9') {
        size = sfRenderWindow_getSize(window);
        screen = sfTexture_create(size.x, size.y);
        sfTexture_updateFromRenderWindow(screen, window, 0, 0);
        shot = sfTexture_copyToImage(screen);
        if (!shot || sfImage_saveToFile((const sfImage *)shot, name) == sfFalse)
            return (-1);
        if (++name[36] > '9') {
            name[36] = '0';
            name[35]++;
        }
    }
    return (0);
}
