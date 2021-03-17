/*
** EPITECH PROJECT, 2019
** print.c
** File description:
** all usefull function for print something
*/

#include "my.h"
#include "matchstick.h"

void my_print_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        my_printf("%s\n", map[i]);
        i = i + 1;
    }
}

void my_print_turn(int evt)
{
    if (evt == PLAYER)
        my_putstr("Your turn:\n");
    else if (evt == AI)
        my_putstr("AI's turn...\n");
}

int my_user_print_line(s_game *game)
{
    my_putstr("Line: ");
    if ((game->s = get_next_line(0)) == NULL)
        return (-1);
    if ((game->user_line = my_get_line(game)) == -1)
        return (-2);
    return (0);
}

int my_user_print_stick(s_game *game)
{
    my_putstr("Matches: ");
    if ((game->s = get_next_line(0)) == NULL)
        return (-1);
    if ((game->user_stick = my_get_stick(game)) == -1)
        return (-2);
    return (0);
}

int my_print_all(s_game *game)
{
    int status = my_user_print_line(game);

    if ((status == -1))
        return (-1);
    else if ((status == -2))
        return (my_print_all(game));
    status = my_user_print_stick(game);
    if ((status == -1))
        return (-1);
    else if ((status == -2))
        return (my_print_all(game));
    my_print_game_info(game);
    return (0);
}
