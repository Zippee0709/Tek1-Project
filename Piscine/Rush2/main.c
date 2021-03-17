/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for step 2
*/

int rush2(char const *str, char wanted);
int my_strlen(char const *str);
int my_check_char(char c);

int main(int ac, char **av)
{
    int i = 2;

    if (ac < 2)
        return (84);
    while (i < ac) {
        if (my_strlen(av[i]) > 1 || my_check_char(av[i][0]) != 1)
            return (84);
        else
            rush2(av[1], av[i][0]);
        i = i + 1;
    }
    return (0);
}
