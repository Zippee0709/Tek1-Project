/*
** EPITECH PROJECT, 2018
** mylist.h
** File description:
** struct of chained list
*/
 
typedef struct linked_list
{
    void *data;
    struct linked_list *next;
}linked_list_t;
