/*
** EPITECH PROJECT, 2018
** my_str_isupper.c
** File description:
** check my str if all char is maj
*/

int my_check_letter_maj(char c);

int my_str_isupper(char const *str)
{
    int i = 0;
    int status = 1;

    while (str[i] != '\0') {
        if (my_check_letter_maj(str[i]) == 1)
            status = 1;
        else {
            status = 0;
            return (status);
        }
        i = i + 1;
    }
    return (status);
}
