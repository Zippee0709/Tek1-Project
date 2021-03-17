/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int lensrc = nb;
    int lendest = my_strlen(dest);
    int lentotal = lensrc + lendest;
    int i = 0;

    while (dest[lendest] != '\0') {
        lendest = lendest + 1;
    }
    while (lendest != lentotal) {
        dest[lendest] = src[i];
        lendest = lendest + 1;
        i += 1;
    }
    dest[lendest] = '\0';
    return (dest);
}
