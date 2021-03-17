/*
** EPITECH PROJECT, 2019
** get_data.c
** File description:
** get_data.c
*/

#include "lemin.h"
#include "my.h"

int my_get_ants_length(DlistAnts *ants)
{
    int nb = 0;

    while (ants != NULL) {
        nb++;
        ants = ants->next;
    }
    return (nb);
}

int my_get_room(char **str, char *msg)
{
    int y = 0;
    int nb = 0;

    while (str[y] != NULL) {
        if (my_strncmp(str[y], msg, my_strlen(msg)) == 0) {
            y++;
            nb = my_get_nbr(str[y]);
            return (nb);
        }
        y++;
    }
    return (-1);
}

int my_get_nb_tunnels(char **str)
{
    int y = 0;
    int nb = 0;

    while (str[y] != NULL) {
        if (my_check_str_is_tunnel(str[y]) == 0)
            nb++;
        y++;
    }
    return (nb);
}

int my_get_nb_vertices(char **str)
{
    int y = 0;
    int nb = 0;

    while (str[y] != NULL) {
        if (my_check_str_only_nbr(str[y]) == 0)
            nb++;
        y++;
    }
    return (nb);
}
