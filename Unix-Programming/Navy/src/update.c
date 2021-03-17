/*
** EPITECH PROJECT, 2019
** update.c
** File description:
** update
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

int get_number_from_letter(char letter)
{
    int i = 0;
    int num = 0;
    char str_letter[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int str_number[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    while (letter != str_letter[i] && str_letter[i] != '\0')
        i = i + 1;
    if (str_letter[i] == '\0')
        return (-1);
    num = str_number[i];
    return (num);
}

int my_get_number(char letter)
{
    int i = 0;

    if (letter >= 'A' && letter <= 'H') {
        i = get_number_from_letter(letter);
        return (i);
    }
    else if (letter >= '1' && letter <= '9')
        i = letter - '0';
    return (i);
}

void my_send_hit_missed_signal(pid_t pid, char save)
{
    struct sigaction signal = {0};

    sigemptyset(&signal.sa_mask);
    signal.sa_handler = my_handler_sent;
    usleep(10000);
    if (save == 'x')
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    sigaction(SIGUSR1, &signal, NULL);
    pause();
}

void my_update_map(char map[MAP_MAX][MAP_MAX], int letter, int number,
        pid_t pid)
{
    char save = 0;

    if ((map[number][letter] >= '0' && map[number][letter] <= '9') ||
        map[number][letter] == 'x') {
        my_putstr(": hit\n\n");
        map[number][letter] = 'x';
        save = 'x';
        my_send_hit_missed_signal(pid, save);
    }
    else {
        my_putstr(": missed\n\n");
        map[number][letter] = 'o';
        save = 'o';
        my_send_hit_missed_signal(pid, save);
    }
}

void my_update(char map[MAP_MAX][MAP_MAX], pid_t pid_one, pid_t pid_two)
{
    char *coord = ptr;
    int letter = my_get_number(coord[0]);
    int number = my_get_number(coord[1]) - 1;

    my_putstr(coord);
    if (pid_one == 0)
        my_update_map(map, letter, number, pid_two);
    else
        my_update_map(map, letter, number, pid_one);
}
