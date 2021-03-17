/*
** EPITECH PROJECT, 2018
** 101pong
** File description:
** 101pong
*/

#include "pong.h"
#include "math.h"

void make_pong(pong_s *pong, int n)
{
    pong_s copy;
    float angle;
    copy.x0 = pong->x1 - pong->x0;
    copy.y0 = pong->y1 - pong->y0;
    copy.z0 = pong->z1 - pong->z0;
    printf("The velocity vector of the ball is :\n");
    printf("(%.2f, %.2f, %.2f)\n", copy.x0, copy.y0, copy.z0);
    copy.x1 = pong->x1 + (n * copy.x0);
    copy.y1 = pong->y1 + (n * copy.y0);
    copy.z1 = pong->z1 + (n * copy.z0);
    printf("At time t + %d, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", copy.x1, copy.y1, copy.z1);
    angle = sqrt(pow(copy.x0, 2) + pow(copy.y0, 2) + pow(copy.z0, 2));
    angle = (fabs(copy.z0 / angle));
    angle = (180 * (asin(angle) / M_PI));
    if ((copy.x0 * (-1) + copy.y0 * (-1) + copy.z0 * (-1)) >= 0) {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", angle);
    } else
        printf("The ball won't reach the bat.\n");
}

void init_pong (pong_s *pong, char **av)
{
    pong->x0 = atof(av[1]);
    pong->y0 = atof(av[2]);
    pong->z0 = atof(av[3]);
    pong->x1 = atof(av[4]);
    pong->y1 = atof(av[5]);
    pong->z1 = atof(av[6]);
}

int main(int ac, char **av)
{
    pong_s pong;
    int n = atoi(av[7]);
    if (ac == 8) {
        init_pong(&pong, av);
        make_pong(&pong, n);
    } else
        return (84);
    return (0);
}
