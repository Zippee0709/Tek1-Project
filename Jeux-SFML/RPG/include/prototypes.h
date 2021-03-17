/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

/*         lib.c             */
int mstrlen(char const *str, int a);
int get_nbr(char const *s);
char *str_cat(char *s1, char *s2);
FILE *open_file(char const *filepath);
char *read_file(char const *filepath);

/*         useful.c          */
sfRenderWindow *create_window(bool fullscreen, char const *name);
sfSprite *create_sprite(sfTexture **texture, char const *str, sfVector2f scale);
sfVector2f create_vector(float x, float y, sfVector2f scale);
sfIntRect create_rect(int top, int left, int width, int height);
void move_rect(sfIntRect *rect, int offset, int max);

/*         useful2.c          */
sfText *create_text(char *str, char const *font, sfColor color, sfVector2f vec);
sfVector2f return_size(sfTexture *texture);
void init_fctptr(sprite_t *obj);

/*         my_rpg.c          */
int my_rpg(void);

/*         create_menu.c     */
int load_menu(menu_t *menu);

/*         destroy_resources.c    */
int destroy_resources(rpg_t *rpg);

/*         draw_sprites.c    */
void manage_menu_events(sprite_t *player, sfEvent event);
void draw_pause_sprites(rpg_t *rpg);
void draw_sprites(rpg_t *rpg, menu_t *menu, sprite_t *pnj);

/*         errors.c          */
int errors(char *envp[]);

/*         events.c          */
void change_screen(rpg_t *rpg, sfEvent event);
void manage_menu_events(sprite_t *player, sfEvent event);
void manage_game_events(rpg_t *rpg, sfEvent event);
void manage_events(rpg_t *rpg, menu_t *menu);

/*         objects.c         */
object_t *load_objects(object_t *obj, int sz, char const **path, sfVector2f *p);

/*         player.c          */
void player_update(sprite_t *sprite, rpg_t *rpg);

/*         transition.c      */
void transition(sfRenderWindow *window, sprite_t *mist);
int create_transition(sprite_t *mist);

/*         random.c          */
int new_seed(void);

/*         loading_screen.c  */
void loading_screen(void *data);
int init_loading_screen(loading_t *screen);

/*         inventory.c       */
inventory_t *init_inventory(void);

/*         cursor.c          */
cursor_t init_cursor(sfRenderWindow *window);
void cursor_position(sfRenderWindow *window, cursor_t *curs, sfVector2f offset);

/*         map_gen.c         */
tileset_t *gen(char const *file, FILE *fd);
char **create_proto(char const *file, FILE *fd);

/*         map_gen2.c        */
int count_lines(char *buf);
char **create_proto(char const *file, FILE *fd);

/*         menu_fct.c        */
void play_game(rpg_t *rpg);
void load_game(rpg_t *rpg);
void exit_game(rpg_t *rpg);
void help_game(rpg_t *rpg);

/*         player_fct.c      */
int move_right(sprite_t *sprite, sfVector2f blck, char **coll, sfVector2f scle);
int move_left(sprite_t *sprite, sfVector2f blck, char **coll, sfVector2f scale);
int move_up(sprite_t *sprite, sfVector2f blck, char **coll, sfVector2f scale);
int move_down(sprite_t *sprite, sfVector2f blck, char **coll, sfVector2f scale);

/*         pause_fct         */
int pause_new(rpg_t *rpg);
int pause_continue(rpg_t *rpg);
int pause_exit(rpg_t *rpg);
int pause_option(rpg_t *rpg);

/*         load_maps.c      */
tileset_t **load_maps(void);

/*         pnj.c            */
int create_pnj(sprite_t *pnj, int top, int x, int y);
void pnj_event(rpg_t *rpg, sprite_t *pnj);
int create_dial(rpg_t *rpg, int top, int x, int y);

/*         enemies.c            */
int create_enemies(sprite_t *sprite);
void enemies_update(rpg_t *rpg);

/*         draw_menu.c            */
void draw_enemies(window_t *window, rpg_t *rpg);

/*         init_stat.c            */
stat_t init_stat(int hp, int max_hp, int attack, int defense);
int load_stat_menu(rpg_t *rpg);
void update_stat_menu_status(rpg_t *rpg, stat_t stat);

/*         button_scale.c            */
void cursor_move_on_menu(cursor_t *cursor, menu_t *menu);

/*         convert.c            */

char *convert_int_to_string(int nb);

/*         draw_stat.c            */
void draw_stat(window_t *window, stat_t stat);

void shot_rainbow(window_t *window, sfSprite *player, rpg_t *rpg);
void player_global_intersect(rpg_t *rpg);

int screen_shot(const sfRenderWindow *window);

void move_view(rpg_t *rpg);

sfFloatRect get_sizemap(char **map);

int load_all(rpg_t *rpg, menu_t *menu, sprite_t *pnj);

/*         quest.c                   */
int create_quest_button(button_t *quest, int top, int x, int y);
int create_quest_infos(button_t *quest, int top, int x, int y);
int load_quest(rpg_t *rpg);

/*         snow.c                    */
particules_t *create_particules(void);
void update_snow(particules_t *snow, sfVector2f offset);

sfVector2f create_vector2f(int x, int y, sfVector2f scale);
#endif
