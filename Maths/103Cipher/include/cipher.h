/*
** EPITECH PROJECT, 2018
** cipher.h
** File description:
** all prototypes and struct for cipher project
*/

#ifndef CIPHER_H
#define CIPHER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct cipher
{
    int **msg;
    int height;
    int **msg_matrix;
    int **matrix;
    int size;
    int flag;
}cipher_s;

void my_putchar_err(char c);
void my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);

void my_cipher(char **av, cipher_s *cipher);
void init_cipher(char **av, cipher_s *cipher);
void help(void);
int **my_get_all_nbr(char const *str, int size);

int my_matrix_size(char const *str);
int my_get_height(char const *str, int size_m);
int **my_malloc_msg_matrix(char const *str, int size_m);
int **my_msg_convert(char const *str, int size_m);
void my_free_matrix(int **matrix);

int **my_calc_matrix(int **matrix, int **key, int **msg, int size);

void my_print_key_matrix(int **matrix, int size, int height);
void my_print_encrypted_matrix(int **matrix, int size, int height);

#endif
