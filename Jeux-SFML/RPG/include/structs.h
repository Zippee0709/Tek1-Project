/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** structs.h
*/

#ifndef STRUCTS_H
#define STRUCTS_H

typedef sfRenderWindow *(*window_f)(int, char *);
typedef sfSprite *(*sprite_f)(sfTexture **, char const *, sfVector2f scale);
typedef sfIntRect (*rect_f)(int, int, int, int);
typedef sfVector2f (*vector_f)(float, float, sfVector2f scale);
typedef sfVector2i (*mouse_position_f)(const sfRenderWindow *relativeTo);
typedef sfVertex *(*get_vertex_f)(sfVertexArray *vertexArray, size_t index);
typedef void (*draw_sprite_f)(sfRenderWindow *, const sfSprite *,
const sfRenderStates *);

enum return_values_e {
    FAILURE = 1,
    SUCCESS = 0
};

enum states_e {
    MENU,
    GAME,
    PAUSE,
    HTP
};

enum move_e
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};


/*
** ===================================================
**                      SNOW_STRUCT
** ===================================================
*/

typedef struct particules_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfClock *clock;
    float impact;
    struct particules_s *next;
} particules_t;

/*
** ===================================================
**                      MAP_STRUCT
** ===================================================
*/

typedef struct tileset_s
{
    sfSprite *tile;
    sfTexture *txture;
    sfIntRect size;
} tileset_t;

/*
** ===================================================
**                      CURSOR_STRUCT
** ===================================================
*/

typedef struct cursor_s
{
    sfSprite *pointer;
    sfTexture *texture;
    sfVertexArray *trail;
    sfVertexArray *shape;
    sfVector2f pos;
    size_t index;
    unsigned int size;
    mouse_position_f mouse_pos;
    get_vertex_f get_vertex;
} cursor_t;

/*
** ===================================================
**                      LOADING_SCREEN_STRUCT
** ===================================================
*/

typedef struct loading_s
{
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfIntRect rect;
} loading_t;

/*
** ===================================================
**                      OBJECT_STRUCT
** ===================================================
*/

typedef struct s_object
{
    sfTexture *tex;
    sfSprite *spr;
    sfVector2f pos;
    sfIntRect rect;
} object_t;

/*
** ===================================================
**                      WINDOW_STRUCT
** ===================================================
*/

typedef struct window_s
{
    sfRenderWindow *window;
    sfView *view;
    sfEvent event;
    sfVector2f offset;
    draw_sprite_f draw;
} window_t;


/*
** ===================================================
**                      INVENTORY_STRUCT
** ===================================================
*/

typedef struct inventory_s {
    bool active;
    sfSprite *sprite;
    sfTexture *txture;
    sfVector2f pos;
    sfVector2f origin;
} inventory_t;

/*
** ===================================================
**                      STAT_STRUC
** ===================================================
*/

typedef struct stat_s
{
    int hp;
    int max_hp;
    int attack;
    int defense;
    int max_attack;
    int max_defense;
    int level;
    object_t bg;
} stat_t;

/*
** ===================================================
**                      SPRITE_STRUCT
** ===================================================
*/

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f vector;
    int move;
    stat_t stat;
    sprite_f create_sprite;
    rect_f create_rect;
    vector_f create_vector;
} sprite_t;

/*
** ===================================================
**                      BUTTON_STRUCT
** ===================================================
*/

typedef struct button_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vector;
    sprite_f create_sprite;
} button_t;

/*
** ===================================================
**                      SKILL_STRUC
** ===================================================
*/

typedef struct skill_s
{
    int skill_points;
    sfText *skill_p;
    sprite_t bg;
    sprite_t *skill;
    sprite_t *minus;
    sprite_t *add;
    sprite_t reload;
    sprite_t save;
    sprite_t exit;
} skill_t;

/*
** ===================================================
**                      MAIN_STRUCT
** ===================================================
*/

typedef struct rpg_s
{
    window_t screen;
    cursor_t cursor;
    object_t htp;
    sprite_t player;
    sprite_t enemies;
    sprite_t mist;
    object_t *stat_menu;
    sprite_t dial;
    inventory_t *inv;
    tileset_t **map;
    char **coll;
    sfFloatRect max;
    unsigned char index;
    object_t *pause;
    particules_t *snow;
    sfThread *loading;
    button_t *quest;
    bool quest_button;
    bool quest_infos;
    bool shot_display;
    sfVertex *shot;
} rpg_t;

/*
** ===================================================
**                      MENU_STRUCT
** ===================================================
*/

typedef struct menu_s
{
    sprite_t logo[2];
    sprite_t *bg;
    button_t *button;
    void (*ptr_fct[4])(rpg_t *rpg);
} menu_t;

#endif
