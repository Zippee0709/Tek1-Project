/*
** EPITECH PROJECT, 2018
** my_str_isupper.c
** File description:
** write a function that return 1 if the string
   passed as parameter only contains upper case
   alphabetical character an 0 otherwise
*/


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
