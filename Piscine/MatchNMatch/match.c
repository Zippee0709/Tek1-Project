/*
** EPITECH PROJECT, 2018
** match.c
** File description:
** match.c project
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (1);
        i = i + 1;
    }
    return (0);
}

int my_strcmp_asterik(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '*')
            return (1);
        i = i + 1;
    }
    return (0);
}

int match(char const *s1, char const *s2)
{
    if (my_strcmp(s1, s2) == 1 || my_strcmp_asterik(s1) == 1 || my_strcmp_asterik(s1) == 1)
        return (1);
    else if (s1[0] == '\0' && my_strcmp_asterik(s2) == 1)
        return (1);    
    return (0);
}
