/*
** EPITECH PROJECT, 2018
** my_strupcase.c
** File description:
** write a function that puts every letter of every word in it in upper case
*/
int my_check_letter_min(char c)
{
    if (c >= 97 && c <= 122)
        return (1);
    return (0);
}

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_check_letter_min(str[i]) == 1) {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
