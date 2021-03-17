/*
** EPITECH PROJECT, 2018
** nmatch.c
** File description:
** nmatch.c j'ai pas compris le sujet j'ai essaye mais je comprend pas
*/

int check_number_match(char const *s1, char const *s2)
{
    int i = 0;
    int nb = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {        
        i = i + 1;
    }
    return (0);
}

int nmatch(char const *s1, char const *s2)
{
    int i = 0;
    int nb = 0;

    while (s1[i] != '\0') {
        if (check_number_match(s1, s2) == 1)
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}
