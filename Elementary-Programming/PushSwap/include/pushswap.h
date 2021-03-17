/*
** EPITECH PROJECT, 2018
** pushswap.c
** File description:
** all prototypes and struct for pushswap project
*/

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

typedef struct DlistNode
{
    int value;
    struct DlistNode *back;
    struct DlistNode *next;
}DlistNode;

typedef struct Dlist
{
    int length;
    struct DlistNode *begin;
    struct DlistNode *end;
}Dlist;

int my_init_index(char const *av);
int my_init_status(char const *av);
void help(void);

void my_pushswap(Dlist *list_a, Dlist *list_b, int ac, char **av);

DlistNode *create_element(int const nb);
Dlist *add_begin_list(Dlist *list, int const nb);
Dlist *add_end_list(Dlist *list, int const nb);
Dlist *delete_begin_list(Dlist *list);
Dlist *delete_end_list(Dlist *list);

Dlist *my_sa(Dlist *list);
void my_pa(Dlist **list_a, Dlist **list_b, int i);
void my_pb(Dlist **list_a, Dlist **list_b);

Dlist *new_list(void);
void my_print_list(Dlist *list);
Dlist *my_add_in_list(Dlist *list, int ac, char **av);
Dlist *my_free_list(Dlist *list);

#endif

