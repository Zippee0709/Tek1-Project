/*
** EPITECH PROJECT, 2018
** my_strlowcase.c
** File description:
** write a function that puts every letter 
   of every word int i tin lower case
*/
int my_check_letter_maj(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    return (0);
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_check_letter_maj(str[i]) == 1)
            str[i] = str[i] + 32;
        i = i + 1;
    }
    return (str);
}
