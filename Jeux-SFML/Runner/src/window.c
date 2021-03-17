/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** all usefull function about window
*/

#include "runner.h"

int init_game(s_game *game, char const *str)
{
    create_texture(game);
    create_sprite(game);
    create_position(game);
    create_clock_str(game);
    set_all_rect(game);
    set_all_position(game);
    if (create_map_from_txt(game, str) == -1)
        return (-1);
    return (0);
}

void pending_game(sfRenderWindow *window, s_game *game)
{
    set_texture(game);
    set_texture_rect(game);
    draw_all_sprite(window, game);
    check_nb_monster(game);
    draw_all_monster(window, game);
    sfRenderWindow_display(window);
    clock_background(game);
    clock_sprite(game);
    event_jump(game);
    move_monster_sprite(game);
    if (game->life == 0)
        game->status = 2;
}

int create_window(char const *str)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    s_game game;

    window = sfRenderWindow_create(mode, "my_runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (init_game(&game, str) == -1)
        return (-1);
    while (sfRenderWindow_isOpen(window) == sfTrue) {
        main_run(window, &game);
    }
    destroy_all(window, &game);
    return (0);
}
