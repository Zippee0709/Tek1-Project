/*
** EPITECH PROJECT, 2019
** intersection.c
** File description:
** all usefull function for intersection
*/

#include "intersection.h"

void init_inter(inter_s *inter, char **av)
{
    inter->opt = atoi(av[1]);
    inter->px = atoi(av[2]);
    inter->py = atoi(av[3]);
    inter->pz = atoi(av[4]);
    inter->vx = atoi(av[5]);
    inter->vy = atoi(av[6]);
    inter->vz = atoi(av[7]);
    inter->p = atoi(av[8]);
}

void check_opt(inter_s *inter)
{
    switch (inter->opt) {
    case 1:
        sphere(inter);
        break;
    case 2:
        cylinder(inter);
        break;
    case 3:
        cone(inter);
        break;
    default:
        printf("option must be 1, 2 or 3\n");
        exit(84);
    }
}

void help(void)
{
    printf("Usage\n");
    printf("./104 intersection opt, px, py, pz, vx, vy, vz, p\n\n");
    printf("Description\n");
    printf("opt\t\t surface option: 1for sphere, 2 for cylinder, ");
    printf("3 for a cone\n");
    printf("(px, py, pz)\t coordiantes of a point by witch the light ");
    printf("ray passes through\n");
    printf("p\t\t parameter: radius of the sphere, radius of the cylinder, ");
    printf("or angle formed by the cone and th Z_axis\n");
}

void intersection(int ac, char **av)
{
    int i = 1;
    inter_s inter;

    if (ac != 9) {
        fprintf(stderr, "Please check -h for binarie usage\n");
        exit(84);
    }
    while (i != ac) {
        if (my_str_isnum(av[i]) == 0) {
            fprintf(stderr, "The argument must be number\n");
            exit(84);
        }
        i = i + 1;
    }
    init_inter(&inter, av);
    check_opt(&inter);
}
