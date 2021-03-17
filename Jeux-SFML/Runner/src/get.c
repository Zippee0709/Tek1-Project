/*
** EPITECH PROJECT, 2019
** ne get.c
** File description:
** all usefull function for get something
*/

#include "runner.h"

int get_size_with_stat(char const *str)
{
    struct stat info;
    int size = 0;
    
    if (stat(str, &info) == -1) {
        my_putstr_err("Error : read stat failed\n");
        return (-1);
    }
    size = (int)info.st_size;
    return (size);
}
