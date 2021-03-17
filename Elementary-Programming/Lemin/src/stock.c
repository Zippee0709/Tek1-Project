/*
** EPITECH PROJECT, 2019
** stock.c
** File description:
** stock.c
*/

#include "lemin.h"
#include "my.h"

char **my_stock_all_tunnels(char **tab)
{
    int y = 0;
    int i = 0;
    int size = my_get_nb_tunnels(tab);
    char **dest = my_malloc_dtab(size, 3);

    while (tab[y] != NULL) {
        if (my_check_str_is_tunnel(tab[y]) == 0) {
            dest[i] = my_strcpy(dest[i], tab[y]);
            i++;
        }
        y++;
    }
    if (i == 0)
        return (NULL);
    return (dest);
}

char **my_stock_all_rooms(char **tab, int size)
{
    int y = 0;
    int i = 0;
    int length = 0;
    char **rooms = malloc(sizeof(char *) * (size + 1));

    if (rooms == NULL)
        return (NULL);
    while (tab[y] != NULL) {
        if (my_check_str_only_nbr(tab[y]) == 0) {
            length = my_strlen(tab[y]);
            rooms[i] = malloc(sizeof(char) * (length + 1));
            rooms[i] = my_strcpy(rooms[i], tab[y]);
            i++;
        }
        y++;
    }
    rooms[i] = NULL;
    return (rooms);
}

void my_convert_tunnel_to_connection(Graph *graph, char **tab)
{
    int y = 0;
    Vector_t pos;

    while (tab[y] != NULL) {
        pos.x = tab[y][0] - '0';
        pos.y = tab[y][2] - '0';
        add_edge(graph, pos.x, pos.y);
        y++;
    }
}
