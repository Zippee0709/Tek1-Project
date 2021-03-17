/*
** EPITECH PROJECT, 2019
** recup_tetriminos_data.c
** File description:
** recup_tetriminos_data.c
*/

#include "tetris.h"
#include "my.h"

int tetriminos_files(DIR *dir, tetrimino_caract_t **caract)
{
    struct dirent *dir_info;
    int errno = 0;
    char *filepath;
    int j = 0;

    for (int i = 0; (dir_info = readdir(dir)) != NULL; i++) {
        if (dir_info->d_name[0] != '.' && dir_info->d_type == DT_REG) {
            filepath = my_strcatdup("tetriminos/", dir_info->d_name);
            if (errno > 0) {
                my_putstr_fd(2, "Error, dir_info\n");
                return -1;
            }
            caract[j] = malloc(sizeof(tetrimino_caract_t));
            if (check_tetrimino(filepath, dir_info->d_name, caract[j]) == -1)
                return -1;
            j++;
            free(filepath);
        }
    }
    return (0);
}

int get_nbr_file(DIR *dir)
{
    struct dirent *dir_info;
    int counter = 0;

    while ((dir_info = readdir(dir)) != NULL) {
        if (dir_info->d_name[0] != '.' && dir_info->d_type == DT_REG
            && my_strstr(dir_info->d_name, ".tetrimino\0$") != -1) {
            counter++;
        }
    }
    return counter;
}

int recup_tetriminos_data(tetris_t *tetris)
{
    DIR *tetriminos = opendir("tetriminos/");
    DIR *tetriminos_bis = opendir("tetriminos/");
    int nbr_file = get_nbr_file(tetriminos_bis);

    tetris->tetriminos = malloc(sizeof(tetrimino_caract_t *) * (nbr_file + 1));
    if (tetriminos == NULL || tetris->tetriminos == NULL) {
        my_putstr_fd(2, "Error, tetriminos\n");
        return -1;
    }
    if (tetriminos_files(tetriminos, tetris->tetriminos) == -1)
        return -1;
    tetris->tetriminos[nbr_file] = NULL;
    closedir(tetriminos_bis);
    closedir(tetriminos);
    return 0;
}
