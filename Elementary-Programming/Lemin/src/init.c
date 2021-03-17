/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
*/

#include "lemin.h"
#include "my.h"

int **my_init_previous_tab(char **rooms, int size)
{
    int i = 0;
    int **previous = my_malloc_int_dtab(size, 2);

    if (previous == NULL)
        return (NULL);
    while (i < size) {
        previous[i][0] = my_get_nbr(rooms[i]);
        previous[i][1] = -1;
        previous[i][2] = '\0';
        i++;
    }
    previous[i] = NULL;
    return (previous);
}

int **my_init_status_tab(char **rooms, int size, int start)
{
    int i = 0;
    int nb = 0;
    int **status = my_malloc_int_dtab(size, 3);

    if (status == NULL)
        return (NULL);
    while (i < size) {
        nb = my_get_nbr(rooms[i]);
        status[i][0] = nb;
        if (nb == start) {
            status[i][1] = 0;
            status[i][2] = 1;
        } else {
            status[i][1] = -1;
            status[i][2] = 0;
        }
        status[i][3] = '\0';
        i++;
    }
    status[i] = NULL;
    return (status);
}

DlistAnts *init_ants_list(char **tab, int start, int nb_ants)
{
    int i = 1;
    DlistAnts *ants = NULL;

    if (nb_ants <= 0)
        return (NULL);
    while (i <= nb_ants) {
        ants = add_ants(ants, i, start);
        i++;
    }
    return (ants);
}

void my_init_new_graph(Global_t *global)
{
    int vertices = my_get_nb_vertices(global->tab);
    global->tunnels = my_stock_all_tunnels(global->tab);
    global->rooms = my_stock_all_rooms(global->tab, vertices);
    global->start = my_get_room(global->tab, "##start");
    global->end = my_get_room(global->tab, "##end");
    global->nb_ants = my_get_nbr(global->tab[0]);
    global->ants = init_ants_list(global->tab, global->start, global->nb_ants);
    global->graph = new_graph(vertices, 0);
    global->graph->nb_vertices = vertices;
    global->previous = my_init_previous_tab(global->rooms, vertices);
    global->status = my_init_status_tab(global->rooms, vertices, global->start);
    my_convert_tunnel_to_connection(global->graph, global->tunnels);
    global->nb_road = find_basic_possibility(global->graph, global->start,
                                            global->end);
    global->close = new_graph(global->nb_road, 1);
    global->close->nb_vertices = global->nb_road;
}
