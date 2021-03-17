/*
** EPITECH PROJECT, 2019
** read_pos2.c
** File description:
** read_pos second file
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"

static int check_same_coord_given(int *pos, int actual_pos, int i)
{
    for (int j = i + 1; pos[j] != -1; j++) {
        if (actual_pos == pos[j]) {
            return (-1);
        }
    }
    return (0);
}

int check_error(char **parse, int actual_pos)
{
    static int pos[1000];
    static int counter = 0;

    pos[counter] = my_getnbr(parse[1]);
    if (((my_getnbr(parse[1]) - my_getnbr(parse[2])) % 10) == 0)
        for (; pos[counter] != my_getnbr(parse[2]); counter++)
            pos[counter + 1] = pos[counter] + 10;
    else
        for (; pos[counter] != my_getnbr(parse[2]); counter++)
            pos[counter + 1] = pos[counter] + 1;
    pos[counter + 2] = -1;
    for (int i = 0; pos[i] != -1; i++) {
        actual_pos = pos[i];
        if (check_same_coord_given(pos, actual_pos, i) == -1)
            return (-1);
    }
    counter++;
    return (0);
}

int check_boat_same_nb(char **pos)
{
    for (int i = 0; pos[i] != NULL; i++) {
        for (int j = i + 1; pos[j] != NULL; j++) {
            if (pos[j][0] == pos[i][0]) {
                return (-1);
            }
        }
    }
    return (0);
}

int my_check_nb_boat(char **pos)
{
    int i = 0;
    int nb = 0;

    while (pos[i] != NULL) {
        if (pos[i][0] >= '2' && pos[i][0] <= '5')
            nb = nb + pos[i][0] - '0';
        else
            return (-1);
        i++;
    }
    if (nb != 14 || i != 4)
        return (-1);
    else if (check_boat_same_nb(pos) == -1)
        return (-1);
    return (0);
}
