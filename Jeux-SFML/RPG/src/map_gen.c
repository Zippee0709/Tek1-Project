/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** map_generation
*/

#include "my_rpg.h"

static int is_wrong_tile(char const *image, int nb)
{
    sfTexture *texture = sfTexture_createFromFile(image, NULL);

    if (nb <= 0)
        return (0);
    if (!texture || nb >= sfTexture_getSize(texture).x)
        return (-1);
    return (0);
}

static void set_map(tileset_t *map, int i, int a, int b)
{
    sfVector2f scale = {720., 480.};
    sfVector2f resize = {(RES_X + 0.) / 720., (RES_Y + 0.) / 480.};

    sfSprite_setScale(map[i].tile, resize);
    sfSprite_setTexture(map[i].tile, map[i].txture, sfTrue);
    sfSprite_setPosition(map[i].tile,
    create_vector(DEFAULT_OFFSET(b), DEFAULT_OFFSET(a), scale));
}

static int init_tileset(tileset_t *map, char **proto, sfVector2i s, char *txtr)
{
    int i = -1;
    sfVector2f scale = {720., 480.};
    sfVector2f resize = {(RES_X + 0.) / 720., (RES_Y + 0.) / 480.};

    for (int a = 0; proto[a] != NULL; a++) {
        for (int b = 0; proto[a][b] ^ '\n' && proto[a][b]; b++) {
            map[++i].tile = sfSprite_create();
            if (is_wrong_tile(txtr, (s.x * (proto[a][b] - '0')) - 1) < 0)
                return (-1);
            map[i].size = create_rect(0, s.x * (proto[a][b] - 49), s.x, s.y);
            if ((proto[a][b] - 48) > 0)
                map[i].txture = sfTexture_createFromFile(txtr, &map[i].size);
            else
                map[i].txture = sfTexture_createFromFile(EMPTY, NULL);
            if (!map[i].txture) return (-1);
            set_map(map, i, a, b);
        }
    }
    map[++i].tile = NULL;
    return (0);
}

static sfVector2i get_image_info(char const *file, FILE *fd, char **txture)
{
    sfVector2i size = {-1, -1};
    char *buf = NULL;
    size_t res = 0;
    int index = 0;

    res = getline(&buf, &res, fd);
    if (res == EOF || buf[0] == '\n')
        return (size);
    size.x = get_nbr(buf);
    index += (buf[0] == '-') ? 1 : 0;
    while (buf[index] >= '0' && buf[index++] <= '9');
    size.y = get_nbr(&buf[++index]);
    for (index = 0; buf[index] <= 'a' || buf[index] >= 'z'; index++);
    *txture = &buf[index++];
    (*txture)[res - index] = '\0';
    return (size);
}

tileset_t *gen(char const *file, FILE *fd)
{
    char *txture = NULL;
    sfVector2i size = get_image_info(file, fd, &txture);
    char **proto = create_proto(file, fd);
    tileset_t *buf = malloc(sizeof(tileset_t) * mstrlen(read_file(file), 0));

    if (!proto || !buf || size.x < 0 || size.y < 0 ||
        init_tileset(buf, proto, size, txture) < 0) {
        write(2, "Map wasn't generated well.\n", 27);
        return (NULL);
    }
    return (buf);
}
