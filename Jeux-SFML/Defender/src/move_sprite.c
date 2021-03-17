/*
** EPITECH PROJECT, 2019
** move_sprite.c
** File description:
** move_sprite.c
*/

#include "my_defender.h"

void move_sprite_dlist_ground(Dlist_node *sp, Dlist_node *gr, float offset)
{
    if (sp->obj.pos.x < gr->obj.pos.x - 5)
        sp->obj.pos.x += offset;
    else if (sp->obj.pos.y < gr->obj.pos.y)
        sp->obj.pos.y += offset;
    else if (sp->obj.pos.x > gr->obj.pos.x - 5)
        sp->obj.pos.x -= offset;
    else if (sp->obj.pos.y > gr->obj.pos.y)
        sp->obj.pos.y -= offset;
}

void move_shots_dlist_enemies(Dlist_node *sp, Dlist_node *gr)
{
    sfVector2f s_pos = sp->obj.pos;
    sfVector2f g_pos = gr->obj.pos;

    g_pos.x += 25;
    g_pos.y += 15;
    sp->obj.pos.x += ((s_pos.x - g_pos.x) / 60 * -5);
    sp->obj.pos.y += ((s_pos.y - g_pos.y) / 60 * -5);
}

void move_sprite_dlist(Dlist *list , Dlist *ground)
{
    Dlist_node *sp = list->begin;
    Dlist_node *gr = ground->begin->next;

    while (sp != NULL) {
        while (gr->obj.pos.x <= sp->obj.pos.x + 5 &&
              gr->obj.pos.y <= sp->obj.pos.y) {
            if (gr->next == NULL) {
                gr = ground->end;
                break;
            }
            gr = gr->next;
        }
        move_sprite_dlist_ground(sp, gr, 2);
        my_sprite_move_rect(sp, sp->obj.clock);
        sp = sp->next;
        gr = ground->begin->next;
    }
}

int move_shots_dlist(Dlist *list, Dlist *enemies)
{
    Dlist_node *tmp;
    Dlist_node *monster;

    if (list == NULL || enemies == NULL)
        return (0);
    tmp = list->begin;
    monster = enemies->begin;
    while (tmp != NULL) {
        move_shots_dlist_enemies(tmp, monster);
        tmp = tmp->next;
    }
    return (0);
}
