/*
** EPITECH PROJECT, 2019
** tower.c
** File description:
** tower.c
*/

#include "my_defender.h"

Dlist *mu_fill_tower_dlist(Dlist *list, Dlist_node *element)
{
    if (list == NULL) {
        list = malloc(sizeof(*list));
        if (list == NULL) {
            my_putstr_err("Error : Allocation memory failed\n");
            return (NULL);
        }
        list->lenght = 0;
        list->begin = element;
        list->end = element;
    }
    else {
        list->end->next = element;
        element->back = list->end;
        list->end = element;
    }
}

Dlist *my_init_and_fill_tower(Dlist *list, sfTexture *texture, sfVector2f pos)
{
    Dlist_node *element = malloc(sizeof(*element));

    if (element == NULL) {
        my_putstr_err("Error : Allocation memory failed\n");
        return (NULL);
    }
    element->sprite = sfSprite_create();
    element->texture = texture;
    element->pos = pos;
    element->back = NULL;
    element->next = NULL;
    return (list);
}
