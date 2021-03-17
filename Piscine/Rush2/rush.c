/*
** EPITECH PROJECT, 2018
** rush.c
*1* File description:
** rush.c
*/

void my_putchar(char c);
void my_put_nbr(int nb);

int my_check_char(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}

int my_count_char(char const *str)
{
    int i = 0;
    int nb_c = 0;

    while (str[i] != '\0') {
        if (my_check_char(str[i]) == 1)
            nb_c = nb_c + 1;
        i = i + 1;
    }
    return (nb_c);
}

void my_print_rush(int nb_c, char wanted, int nb_s)
{
    my_putchar(wanted);
    my_putchar(':');
    my_put_nbr(nb_c);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(nb_c * 100  / nb_s);
    my_putchar('.');
    my_put_nbr((nb_c * 100 % nb_s) * 2.0833333333334);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

void rush2(char const *str, char wanted)
{
    int i = 0;
    int nb_c = 0;

    while (str[i] != '\0') {
        if (my_check_char(str[i]) == 1 &&
            (str[i] == wanted || str[i] == wanted - 32 ||
            str[i] == wanted + 32))
            nb_c = nb_c + 1;
        i = i + 1;
    }
    my_print_rush(nb_c, wanted, my_count_char(str));
}
