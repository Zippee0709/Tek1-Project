/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** write function who compare beetween 2 string
*/

int my_strlen(char const *str);

int my_char_cmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
        i = i + 1;
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_strlen(s1);
    int k = my_strlen(s2);
    int res = 0;

    if (i > k)
        return (-1);
    else if (i < k)
        return (1);
    else
        res = my_char_cmp(s1, s2);
    return (res);
}
