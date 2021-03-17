/*
** EPITECH PROJECT, 2018
** my_params_to_list.c
** File description:
** list all params int the chained list
*/

#include "include/my.h"
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin);
void my_rev_list(linked_list_t **begin);

int my_put_front_list(linked_list_t **list, char *str)
{
    linked_list_t *element = NULL;

    element = malloc(sizeof(*element));

    if (element == NULL)
        return (84);
    element->data = str;
    if (*list == NULL)
        element->next == NULL;
    else        
        element->next = *list;
    *list = element;
    return (0);
}

int my_show_list(linked_list_t *list)
{
    linked_list_t *temp = list;  

    while (temp != NULL) {
        my_putstr(temp->data);
        my_putchar('\n');
        temp = temp->next;
    }
    return (0);
}

linked_list_t *my_params_to_list(int ac , char * const *av)
{
    int i = 0;
    linked_list_t *list = NULL;

    while (av[i] != NULL) {
        my_put_front_list(&list, av[i]);
        i = i + 1;
    }
    my_show_list(list);
    printf("-----------\n");
    return (list);

}

int main(int ac, char **av)
{
    linked_list_t *list = my_params_to_list(ac, av);
    my_rev_list(&list);
    my_show_list(list);
}
