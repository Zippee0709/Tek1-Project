/*
** EPITECH PROJECT, 2018
** cipher.h
** File description:
** init_cipher
*/

#include "cipher.h"

void help(void)
{
    printf("USAGE : ./103cipher Message Key Flag\n");
    printf("DESCRIPTION :\n");
    printf("Message : a message, made of ASCII characters\n");
    printf("Key : the encryption key, made of ASCII characters\n");
    printf("Flag : 0 for the message to be encrypted, 1 to be decrypted\n");
}

void my_cipher_encrypted(char **av, cipher_s *cipher)
{
    cipher->msg = my_msg_convert(av[1], cipher->size);
    cipher->msg_matrix = my_malloc_msg_matrix(av[1], cipher->size);
    cipher->msg_matrix = my_calc_matrix(cipher->msg_matrix, cipher->matrix,
                                        cipher->msg, cipher->size);
    my_print_key_matrix(cipher->matrix, cipher->size, cipher->size);
    printf("\n");
    my_print_encrypted_matrix(cipher->msg_matrix, cipher->size, cipher->height);
    my_free_matrix(cipher->matrix);
    my_free_matrix(cipher->msg);
    my_free_matrix(cipher->msg_matrix);
}

void my_cipher_decrypted(char **av, cipher_s *cipher)
{
    my_free_matrix(cipher->matrix);
    my_free_matrix(cipher->msg);
    my_free_matrix(cipher->msg_matrix);
}

void my_cipher(char **av, cipher_s *cipher)
{
    cipher->flag = my_getnbr(av[3]);
    cipher->size = my_matrix_size(av[2]);
    cipher->height = my_get_height(av[1], cipher->size);
    cipher->matrix = my_msg_convert(av[2], cipher->size);

    if (cipher->flag == 0)
        my_cipher_encrypted(av, cipher);
    /* else if (cipher->flag == 1) */
    /*     cipher->msg = my_get_all_nbr(av[1], cipher->size); */
    /*     my_print_encrypted_matrix(cipher->msg, cipher->size, cipher->height); */
}
