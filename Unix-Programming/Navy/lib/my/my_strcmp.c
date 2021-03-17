/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two strings
*/

int my_strcmp(char *str, char *str2)
{
    int counter = 0;

    while (str[counter] != '\0' || str2[counter] != '\0') {
        if (str[counter] != str2[counter]) {
            return (-1);
        }
        counter++;
    }
    return (0);
}
