/*
** EPITECH PROJECT, 2018
** test_map.c
** File description:
** test_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>
#include <bsq.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int lenght(char *str)
{
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0')
        i = i + 1;
    return (i);
}

int width(char *str)
{
    int i = 0;
    int nb = 0;
    
    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb = nb + 1;
        i = i + 1;
    }
    if (str[i] == '\0' && str[i - 1] != '\n')
        nb = nb + 1;
    return (nb);
}

char **tochar_array(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int wid = width(str);
    int len = lenght(str) + 1;
    char **tab = malloc(sizeof(char *) * wid + 1);

    while (i <= wid) {
        tab[i] = malloc(sizeof(char) * len + 1);
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            tab[j][k] = '\0';
            j = j + 1;
            k = 0;
        }
        else
            tab[j][k] = str[i];
    } 
    if (str[i] == '\0' && str[i - 1] != '\n') {
        tab[j][k] = '\0';
        j = j + 1;
    }
    tab[j] = NULL;
    return (tab);
}

Test(my_bsq, test_my_bsq, .init = redirect_all_std)
{
    bsq_s bsq;
    char *str = NULL;
    char **tab = NULL;
    char *av = "../mouli_maps/intermediate_map_97_21_empty";
    char *av_s = "../mouli_maps_solved/intermediate_map_97_21_empty";

//    init_bsq(&bsq, av);
    str = read_file(av_s);
//    tab = tochar_array(str);
    cr_assert_stdout_eq_str(str);
}
