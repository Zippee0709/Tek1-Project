/*
** EPITECH PROJECT, 2019
** wait_input.c
** File description:
** wait input
*/

#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "my.h"
#include "tetris.h"

int back_to_normal(struct termios termios_p)
{
    termios_p.c_lflag |= ICANON;
    termios_p.c_lflag |= ECHO;
    if (tcsetattr(0, TCSANOW, &termios_p) == -1) {
        my_putstr_fd(2, "Error with tcsetattr().\n");
        return (-1);
    }
    return (0);
}

int wait_input(void)
{
    struct termios termios_p;
    char c;

    if (tcgetattr(0, &termios_p) == -1) {
        my_putstr_fd(2, "Error with tcgetattr().\n");
        return (-1);
    }
    termios_p.c_lflag &= ~ICANON;
    termios_p.c_lflag &= ~ECHO;
    if (tcsetattr(0, TCSANOW, &termios_p) == -1) {
        my_putstr_fd(2, "Error with tcsetattr().\n");
        return (-1);
    }
    read(0, &c, 1);
    if (back_to_normal(termios_p) == -1)
        return (-1);
    return (0);
}
