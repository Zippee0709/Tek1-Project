/*
** EPITECH PROJECT, 2018
** tree.c
** File description:
** rite a function that displays a fir tree, based on its given size
*/
void    print_line_tree(int max_char, int nb_space)
{
    int i = 0;

    while (i != max_char) {
        if (i < nb_space)
            my_putchar(' ');
        else
            my_putchar('*');
        i = i + 1;
    }
}

int my_print_fir(int max_line, int max_char, int nb_space)
{
    int i = 0;

    while (i < max_line) {
        print_line_tree(max_char, nb_space);
        my_putchar('\n');
        nb_space = nb_space - 1;
        max_char = max_char + 1;
        i = i + 1;
    }
}

void    print_tronc(int size)
{
    int i = 0;
    int j = 0;
    int nb_bar = 1 * size;
    int max_char = 3 * size + 1;

    if (my_is_prime(size) == 1)
        nb_bar = nb_bar + 1;
    else if (my_is_prime(size) == 0 && size > 2)
        max_char = max_char - 1;
    while (i < size) {
        j = 0;
        while (j < max_char) {
            if (j < max_char - nb_bar)
                my_putchar(' ');
            else
                my_putchar('|');
            j = j + 1;
        }
        my_putchar('\n');
        i = i + 1;
    }
}

void    tree(int size)
{
    int i = 0;
    int max_char = 3 * size + 1;
    int max_line = 4;
    int nb_space = 3 * size;
    
    if (size <= 0)
        return (0);
    while (i < size) {
        my_print_fir(max_line, max_char, nb_space);
        max_line = max_line + 1;
        max_char = max_char + 2;
        nb_space = nb_space - 2;
        i = i + 1;
    }
    print_tronc(size);
}
