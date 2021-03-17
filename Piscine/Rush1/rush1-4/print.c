/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** print
*/
void my_putchar(char c);

void print_e(int x, int y, int xl, int yl)
{
    if (xl == x || xl == 1)
        my_putchar('B');
    else if (yl == y || yl == 1)
        my_putchar('B');
    else
        my_putchar(' ');
}

void print_d(int x, int y, int xl, int yl)
{
    if (xl == x && yl == y)
        my_putchar('C');
    else
        print_e(x, y, xl, yl);
}

void print_c(int x, int y, int xl, int yl)
{
    if (xl == 1 && yl == y)
        my_putchar('A');
    else
        print_d(x, y, xl, yl);
}

void print_b(int x, int y, int xl, int yl)
{
    if (xl == x && yl == 1)
        my_putchar('C');
    else
        print_c(x, y, xl, yl);
}

void print_a(int x, int y, int xl, int yl)
{
    if (xl == 1 && yl == 1)
        my_putchar('A');
    else
        print_b(x, y, xl, yl);
}
