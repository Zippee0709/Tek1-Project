/*
** EPITECH PROJECT, 2018
** my_params_to_array.c
** File description:
** my_params_to_array function
*/

#include "include/my.h"
#include "include/my_params_to_array.h"


struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param **param = malloc(sizeof(struct info_param) + 1);

    if (param == NULL)
        return (NULL);

    while (i < ac) {
        param[i] = malloc(sizeof(struct info_param));
        param[i]->length = (my_strlen(av[i]) - 1);
        param[i]->str = av[i];
        param[i]->copy = my_strdup(av[i]);
        param[i]->word_array = my_str_to_word_array(param[i]->str);
        i = i + 1;
    }
    param[i] = 0;
    return (*param);
}
/*
int main(int ac, char **av)
{
    int i = 0;
    struct info_param *param = my_params_to_array(ac, av);

    printf("%d\n", param->length);
    printf("%s\n", param->str);
    printf("%s\n", param->copy);

    while (param->word_array[i] != NULL) {
        printf("%s\n", param->word_array[i]);
        i = i + 1;
    }
    return (0);
}
*/
