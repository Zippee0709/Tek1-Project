/*
** EPITECH PROJECT, 2019
** print_help_message.c
** File description:
** print help
*/

#include "my.h"

void print_help_message(char **argv)
{
    my_putstr("Usage:  ");
    my_putstr(argv[0]);
    my_putstr(" [options]\nOptions:\n");
    my_putstr(" --help\t\t\tDisplay this help\n");
    my_putstr(" -L --level={num}\tStart Tetris at level num (def : 1)\n");
    my_putstr(" -l --key-left={K}\tMove the tetrimino LEFT");
    my_putstr("using the K key (def: left arrow)\n");
    my_putstr(" -r --key-right={K}\tMove the tetrimino RIGHT");
    my_putstr("using the K key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}\tTURN the tetrimino clockwise 90d ");
    my_putstr("using the K key (def: toparrow)\n");
    my_putstr(" -d --key-drop={K}\tDROP the tetrimino using");
    my_putstr("the K key (def: down arrow)\n");
    my_putstr(" -q --key-quit={K}\tQUIT the game using the K key");
    my_putstr(" (def: ‘q’ key)\n -p --key-pause={K}\tPAUSE/RESTART the game");
    my_putstr("using the K key (def: space bar)\n");
    my_putstr(" --map-size={row,col}\tSet the numbers of rows and columns");
    my_putstr("of the map (def: 20,10)\n");
    my_putstr(" -w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr(" -D --debug\t\tDebug mode (def: false)\n");
}
