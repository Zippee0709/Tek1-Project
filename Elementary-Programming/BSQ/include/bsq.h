/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** all prototypes and struct for bsq project
*/

#ifndef BSQ_H
#define BSQ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EXIT_ERROR 84
#define EXIT_SUCCESS 0

#define ERROR_OPEN_MSG "Error : open failed\n"
#define ERROR_READ_MSG "Error : read failed\n"
#define ERROR_MALLOC_MSG "Error : malloc failed\n"
#define ERROR_CONTAIN_MSG "Error : invalid character\n"

typedef struct bsq_s
{
    int x;
    int y;
    int index;
    int lenght;
    int width;
    char **tab;
}bsq_s;

char *read_file(char *file);
void my_double_malloc(bsq_s *bsq);
void init_bsq(bsq_s *bsq, char *av);
void only_one_char(bsq_s *bsq);
int my_get_lenght(char *str);
void my_str_to_word_tab(bsq_s *bsq, char *str);

void my_bsq_algorithm(bsq_s *bsq);

void my_check_str(char *str);
void my_check_tmp(bsq_s *bsq, int tmp, int tmp_x, int tmp_y);
void my_replace_tab(bsq_s *bsq);
void only_one_dot(bsq_s *bsq);
void my_print_tab(char **tab);
void my_free_tab(char **tab);

#endif
