/*
** EPITECH PROJECT, 2018
** rush.c
** File description:
** dqsd
*/
void my_putchar(char c);
void my_putstr_err(char const *str);
void print_a(int x, int y, int xl, int yl);
int my_getnbr(char const *str);

void rush(int x, int y)
{
    int xl = 1;
    int yl = 1;

    if (x <= 0 || y <= 0) {
        my_putstr_err("Invalid size\n");
        return;
    }
    while (yl <= y) {
        xl = 1;
        while (xl <= x) {            
            if(x == 1 || y == 1)
                my_putchar('*');
            else
                print_a(x, y, xl, yl);
            xl = xl + 1;
        }
        my_putchar('\n');
        yl = yl + 1;
    }
}

int main(int ac, char **av)
{
    rush(my_getnbr(av[1]), my_getnbr(av[2]));
    return (0);
}
