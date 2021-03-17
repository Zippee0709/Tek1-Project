/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** snow.c
*/

#include "my_rpg.h"

particules_t *create_particules(void)
{
    particules_t *list = NULL;
    particules_t *head = NULL;
    sfVector2f scale = {800., 600.};

    for (unsigned int a = 0; ++a ^ 300; head = list) {
        list = malloc(sizeof(particules_t));
        if (!list)
            return (NULL);
        list->sprite = create_sprite(&list->texture, SNOW, scale);
        list->pos.x = (rand() / (float)RAND_MAX) * ((float)RES_X);
        list->pos.y = (rand() / (float)RAND_MAX) * ((float)RES_Y);
        list->impact = list->pos.y + (200. * (float)RES_Y / 600.);
        list->clock = sfClock_create();
        list->next = head;
    }
    return (list);
}

void update_snow(particules_t *snow, sfVector2f offset)
{
    float a = 200. * (float)RES_X / 800.;
    float b = 250. * (float)RES_Y / 600.;
    sfVector2f q = {5.7 * (float)RES_X / 800., .3 * (float)RES_Y / 600.};
    sfVector2f r = {17. * (float)RES_X / 800., 6. * (float)RES_Y / 600.};

    for (particules_t *tp = snow; tp; tp = tp->next) {
        if (sfClock_getElapsedTime(tp->clock).microseconds > 50000) {
            tp->pos.x += ((rand() / (float)RAND_MAX) * q.x + q.y);
            tp->pos.y += ((rand() / (float)RAND_MAX) * r.x - r.y);
            if (tp->pos.y > tp->impact) {
                tp->pos.x = (rand() / (float)RAND_MAX) *
                    ((float)RES_X + a + offset.x) - a;
                tp->pos.y = (rand() / (float)RAND_MAX) *
                    ((float)RES_Y + b + offset.y) - b;
                tp->impact = tp->pos.y + (200. * (float)RES_Y / 600.);
            }
            sfSprite_setPosition(tp->sprite, tp->pos);
            sfClock_restart(tp->clock);
        }
    }
}
