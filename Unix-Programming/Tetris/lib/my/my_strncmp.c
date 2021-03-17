/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two strings
*/

int my_strncmp(char *str, char *str2, int n)
{
    int counter = 0;

    while (counter < n) {
        if (str[counter] != str2[counter]) {
            return (-1);
        }
        counter++;
    }
    return (0);
}
