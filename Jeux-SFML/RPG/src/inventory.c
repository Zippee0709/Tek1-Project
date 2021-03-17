/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory.c
*/

#include "my_rpg.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(*inventory));
    sfVector2f scale = {1920., 1080.};

    if (!inventory)
        return (NULL);
    inventory->active = false;
    inventory->sprite = create_sprite(&inventory->txture, INVENTORY, scale);
    inventory->origin = create_vector(760, 980, scale);
    inventory->pos = create_vector(760, 580, scale);
    sfSprite_setPosition(inventory->sprite, inventory->origin);
    return (inventory);
}
