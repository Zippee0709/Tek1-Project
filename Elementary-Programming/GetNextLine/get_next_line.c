/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** all usefull function for gnl
*/

#include "include/get_next_line.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_strdup(char *src)
{
    int i = 0;
    int size = my_strlen(src);
    char *copy = malloc(sizeof(char) * (size + READ_SIZE));

    while (src[i] != '\0') {
        copy[i] = src[i];
        i = i + 1;
    }
    copy[i] = '\0';
    return (copy);
}

char *my_check_buf(char *str, char *buf)
{
    int i = 0;
    int j = 0;
    char *cpy = str;
    
    if (str != NULL)
        cpy = my_strdup(str);
    while (cpy[j] != '\0')
        j = j + 1;
    while (buf[i] >= 32 && buf[i] <= 126 && buf[i] != '\n') {
        cpy[j] = buf[i];
        i = i + 1;
        j = j + 1;
    }
    cpy[j] = '\0';
    return (cpy);
}

int my_check_str(char *str, char *buf, int *status)
{
    int i = 0; 

    while (i < READ_SIZE) {
        if (buf[i] == '\n')
            return (1);
        i = i + 1;
    }
    return (0);
}

char *get_next_line(int fd)
{
    static char buf[READ_SIZE];
    char *str = malloc(sizeof(char) * (READ_SIZE + 1));
    int status = 1;
    
    if (str == NULL)
        return (NULL);
    while (status == 1) {
        if (read(fd, buf, READ_SIZE) == -1)
            return (NULL); 
        str = my_check_buf(str, buf);
        if (my_check_str(str, buf, &status) == 1)
            return (str);
    }
    return (str);
}
