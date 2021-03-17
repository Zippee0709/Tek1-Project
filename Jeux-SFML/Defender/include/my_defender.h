/*
** EPITECH PROJECT, 2019
** my_defender.h
** File description:
** all usefull prototypes and data struc for my_defneder project
*/

#ifndef MY_DEFENDER
#define MY_DEFENDER

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_stat
{
    float life;
    float armor;
    float power;
    float speed;
}s_stat;

typedef struct s_obj
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    s_stat stat;
    sfClock *clock;
    int type;
}s_obj;

typedef struct DlistNode
{
    s_obj obj;
    struct DlistNode *back;
    struct DlistNode *next;
}Dlist_node;

typedef struct Dlist
{
    int lenght;
    Dlist_node *begin;
    Dlist_node *end;
}Dlist;

typedef struct s_ground
{
    s_obj UL;
    s_obj UR;
    s_obj DL;
    s_obj DR;
    s_obj HG;
    s_obj VG;
    s_obj BG;
    s_obj GG;
}s_ground;

typedef struct button_s
{
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f pos;
}s_button;

typedef struct text_s
{
    sfText *text_tower;
    sfText *text_skill;
    sfText *text_score;
    sfText *score;
    sfText *castle;
    sfText *castle_life;
}s_text;

typedef struct s_shots
{
    s_obj arrow;
    s_obj fire;
    s_obj rock;
    s_obj ninja;
}s_shots;

typedef struct s_music
{
    sfMusic *game;
    sfMusic *start;
    sfMusic *tower;
    sfMusic *fire;
    sfMusic *arrow;
    sfMusic *rock;
    sfMusic *ninja;
    sfMusic *game_over;
}s_music;

typedef struct s_game
{
    char **map;
    sfVector2i i;
    sfVector2i m_pos;
    sfVector2f tmp;
    s_obj menu;
    s_obj backgr;
    s_obj final;
    s_obj castle;
    s_obj skill;
    s_obj pause;
    s_button play;
    s_button play_again;
    s_button exit;
    s_obj AT;
    s_obj CT;
    s_obj KT;
    s_obj TT;
    s_obj all_tower;

    Dlist *gr;
    Dlist *base_gr;
    Dlist *enemies;
    Dlist *tower_map;
    Dlist *shots;
    s_music music;
    s_ground ground;
    s_shots shots_s;
    s_obj monster;

    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    int status;
    sfBool is_reset;
    int tower_status;
    int error;
    
    sfFont *font;
    s_text text;
    sfClock *clock_monster;
    sfClock *clock_text;
    sfClock *clock_score;
    sfClock *clock_shots;
    sfClock *clock;
    sfTime start;
    sfTime end;
    float start_sec;
    float end_sec;
    float framerate;
    int fps;
    int score;
    int castle_life;
    int tower_shots;
    int escape;
}s_game;

enum type
{
    MENU,
    PAUSE,
    GAME,
    FINAL,
    EXIT,
    OPTIONS,
};

enum error
{
    ERROR_TOWER,
    ERROR_SKILL,
};

void my_help(void);
void create_window(void);
void my_create_sprite(s_game *game);
void my_create_texture(s_game *game);
void my_create_ground_sprite(s_ground *ground);
void my_create_ground_texture(s_ground *ground);
void my_create_rectangle_shape(s_game *game);
void my_create_shots_texture(s_shots *shots);

Dlist *my_fill_dlist_ground(s_game *game, char **map, char letter, Dlist *list);

void init_game(s_game *game);
void init_game_button(s_game *game);
void init_text(s_game *game);
void init_pos(s_game *game);
void init_float_rect(sfFloatRect *rect, sfVector2f min, sfVector2f max);
void init_music(s_game *game);
s_stat init_stat_tower(float value);
void init_text_again(s_game *game);

void analyse_event(s_game *game);
void manage_mouse_click(s_game *game);

int check_pos_value(sfVector2i mouse, sfVector2f s_pos, sfVector2f max);
int check_fpos_value(sfVector2f mouse, sfVector2f s_pos, sfVector2f max);
int check_click_on_all_tower(sfVector2f s_pos, sfVector2i m_pos);
int check_sprite_error_tower(Dlist *list, sfVector2f pos, int status, int *error);

int check_click_on_tower(s_game *game, Dlist *list, sfVector2i m_pos);
int check_click_on_all_skill(sfVector2f s_pos, sfVector2i m_pos);
int check_click_on_list(s_game *game, Dlist *list, sfVector2i m_pos);

void draw_score(s_game *game);

void my_set_texture(s_game *game);
void my_set_position(s_game *game);
void my_set_ground_texture(s_ground *ground);
void run_all(s_game *game);

void draw_menu(s_game *game);
void draw_game(s_game *game);
void draw_ground_dlist(Dlist *list, s_game *game);
void draw_sprite_dlist(Dlist *list, s_game *game);
void draw_tower_attack(s_game *game);
void draw_castle_life(s_game *game);

void update_tower_status(s_game *game, sfVector2i m_pos);
void my_update_game(s_game *game);

void my_free_double_tab(char **tab);
void my_free_all(s_game *game);
void my_free_music(s_game *game);

void my_putchar(char c);
void my_putstr(char *str);
void my_putchar_err(char c);
void my_putstr_err(char const *str);
void my_print_double_tab(char **tab);
int my_strlen_char(char **map, char letter);
char *my_int_convert_str(int nb);

int my_get_lenght(char const *str);
int my_get_height(char const *str);
char *create_map_from_txt(char const *str);
char **my_str_to_word_tab(char *str);

int dlist_lenght(Dlist *list);
Dlist *my_check_map_info(char letter, s_game *game, sfVector2f pos, Dlist *list);
Dlist *push_back_dlist(Dlist *list, s_obj obj, sfVector2f pos);
Dlist *pop_back_dlist(Dlist *list);
Dlist *pop_begin_dlist(Dlist *list);
void my_free_dlist(Dlist *list);
void my_free_clock(s_game *game);

Dlist *my_push_tower_in_the_list(Dlist *list, s_game *game, sfVector2i m_pos);

void my_sprite_move_rect(Dlist_node *sp, sfClock *clock);
void move_sprite_dlist_ground(Dlist_node *sp, Dlist_node *gr, float offset);
void move_shots_dlist_enemies(Dlist_node *sp, Dlist_node *gr);
void move_sprite_dlist(Dlist *list , Dlist *ground);
int move_shots_dlist(Dlist *list, Dlist *enemies);

int check_rect_of_two_pos(sfVector2f s_pos, sfVector2f m_pos, s_game *game);
int check_shots_on_enemies(s_game *game);
int check_life_on_enemies(Dlist *enemies);
void check_tower_status(s_game *game, sfVector2i m_pos);
void check_tower_type(s_game *game);

void manage_resume_click(s_game *game);
void manage_options_click(s_game *game);
void manage_exit_click(s_game *game);

void my_update_game_value(s_game *game);

#endif
