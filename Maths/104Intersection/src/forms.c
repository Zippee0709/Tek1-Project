/*
** EPITECH PROJECT, 2019
** forms.c
** File description:
** all usefull forms func
*/

#include "intersection.h"

float check_x1(float b, float a)
{
    float x1;

    if (a == 0) {
        printf("There is an infinite number of intersection points\n");
        exit(0);
    }
    x1 = -b / (2 * a);
    return (x1);
}

void check_d(float a, float b, float d, inter_s *z)
{
    float x1 = (-b - sqrt(d)) / (2 * a);
    float x2 = (-b + sqrt(d)) / (2 * a);

    if (d == 0) {
        x1 = check_x1(b, a);
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, ", z->px + x1 * z->vx, z->py + x1 * z->vy);
        printf("%.3f)\n", z->pz + x1 * z->vz);
    }
    else if (d > 0) {
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, ", z->px + x2 * z->vx, z->py + x2 * z->vy);
        printf("%.3f)\n", z->pz + x2 * z->vz);
        printf("(%.3f, %.3f, ", z->px + x1 * z->vx, z->py + x1 * z->vy);
        printf("%.3f)\n", z->pz + x1 * z->vz);
    }
    else
        printf("No intersection point.\n");
}

void sphere(inter_s *z)
{
    float a = (z->vx * z->vx) + (z->vy * z->vy) + (z->vz * z->vz);
    float b = (2 * z->px * z->vx) + (2 * z->py * z->vy) + (2 * z->pz * z->vz);
    float c = pow(z->px, 2) + pow(z->py, 2) + pow(z->pz, 2) - pow(z->p, 2);
    float d = b * b - 4 * a * c;

    printf("Sphere of radius %d\n", z->p);
    printf("Line passing through the point (%d, %d, %d) ", z->px, z->py, z->pz);
    printf("and parallel to the vector (%d, %d, %d)\n", z->vx, z->vy, z->vz);
    check_d(a, b, d, z);
}

void cone(inter_s *z)
{
    float angle = (M_PI / 2) - (z->p * M_PI / 180);
    float pow_p = tan(angle) * tan(angle);
    float a = (z->vx * z->vx) + (z->vy * z->vy) - ((z->vz * z->vz) / pow_p);
    float b = (2 * z->px * z->vx) + (2 * z->py * z->vy) - ((2 * z->pz * z->vz) / pow_p);
    float c = (z->px * z->px) + (z->py * z->py) - ((z->pz * z->pz) / pow_p);

    printf("cone with a %d degree angle\n", z->p);
    printf("Line passing through the point (%d, %d, %d) ", z->px, z->py, z->pz);
    printf("and parallel to the vector (%d, %d, %d)\n", z->vx, z->vy, z->vz);
    check_d(a, b, (b * b - 4 * a * c), z);
}

void cylinder(inter_s *z)
{
    float a = (z->vx * z->vx) + (z->vy * z->vy);
    float b = (2 * z->px * z->vx) + (2 * z->py * z->vy);
    float c = (z->px * z->px) + (z->py * z->py) - (z->p * z->p);
    float d = b * b - 4 * a * c;

    printf("Cylinder of radius %d\n", z->p);
    printf("Line passing through the point (%d, %d, %d) ", z->px, z->py, z->pz);
    printf("and parallel to the vector (%d, %d, %d)\n", z->vx, z->vy, z->vz);
    check_d(a, b, d, z);
}
