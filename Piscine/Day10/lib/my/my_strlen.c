/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** function who counts and return number of character found in the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
