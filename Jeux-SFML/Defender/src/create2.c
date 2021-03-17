/*
** EPITECH PROJECT, 2019
** create2.c
** File description:
** create 2
*/

#include "my_defender.h"

void my_create_shots_texture(s_shots *shots)
{
    shots->arrow.sprite = sfSprite_create();
    shots->arrow.texture = sfTexture_createFromFile("img/bball.png", NULL);
    shots->fire.sprite = sfSprite_create();
    shots->fire.texture = sfTexture_createFromFile("img/gball.png", NULL);
    shots->rock.sprite = sfSprite_create();
    shots->rock.texture = sfTexture_createFromFile("img/tball.png", NULL);
    shots->ninja.sprite = sfSprite_create();
    shots->ninja.texture = sfTexture_createFromFile("img/shots.png", NULL);
    shots->arrow.clock = sfClock_create();
    shots->fire.clock = sfClock_create();
    shots->rock.clock = sfClock_create();
    shots->ninja.clock = sfClock_create();
}
