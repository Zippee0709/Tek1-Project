/*
** EPITECH PROJECT, 2018
** cti_itc.c
** File description:
** function who convert int to char and char to int
*/

#include "bistromatic.h"
#include "my.h"

int cti(char c)
{
    int res = c - '0';
    return (res);
}

char itc(int c)
{
    char res = c + '0';
    return (res);
}
