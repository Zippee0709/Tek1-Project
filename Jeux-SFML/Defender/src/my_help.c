/*
** EPITECH PROJECT, 2019
** HELP
** File description:
** description
*/

#include "../include/my_defender.h"

void my_help(void)
{
    char *help = "Usage\n\t./my_defender\nDescription\n"
        "\tHave fun defending your king till death do you part. "
        "Prevent Zombies from destroying the Castle and eat "
        "your King alive\n";

    my_putstr(help);
    return;
}
