/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** write a function who compare beetweed 2 string with N as argument
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
        else
            i = i + 1;
    }
    return (0);
}
