/*
** EPITECH PROJECT, 2019
** 104intersection.h
** File description:
** all prototypes and struct for 104 intersection
*/

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct intersection
{
    int opt;
    int px;
    int py;
    int pz;
    int vx;
    int vy;
    int vz;
    int p;
}inter_s;

void intersection(int ac, char **av);
void sphere(inter_s *z);
void cylinder(inter_s *z);
void cone(inter_s *z);
void help(void);
int my_str_isnum(char const *str);

#endif
