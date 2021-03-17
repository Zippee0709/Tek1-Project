/*
** EPITECH PROJECT, 2018
** bistromatic.h
** File description:
** all prototypes of function and struct use in bistromatic project
*/

#ifndef BISTROMATIC_H
#define BISTROMATIC_H

#define OP_OPEN_PARENT_IDX   0
#define OP_CLOSE_PARENT_IDX  1
#define OP_PLUS_IDX          2
#define OP_SUB_IDX           3
#define OP_NEG_IDX           3
#define OP_MUL_IDX           4
#define OP_DIV_IDX           5
#define OP_MOD_IDX           6

#define EXIT_SUCCESS    0
#define FALSE           0
#define TRUE            1
#define EXIT_USAGE      84
#define EXIT_BASE       84
#define EXIT_SIZE_NEG   84
#define EXIT_MALLOC     84
#define EXIT_READ       84
#define EXIT_OPS        84

#define SYNTHAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct bistromatic
{
    unsigned int size;
    char *expr;
    char *base;
    char *operator;
    int parent;
    int status;
}bistro_s;

typedef struct nb_s
{
    int size1;
    int size2;
    int size_ns;
    int ret;
    int neg;
    char *res;
}nb_s;

int init_bistro(bistro_s *bistro, char **av);
int init_calc(nb_s *calc, char *nb1, char *nb2);
int init_calc_mul(nb_s *calc, char *nb1, char *nb2);

char *eval_expr(bistro_s *bistro);
char *my_eval_np(char **str, char *ops);
char *my_eval_wp(char **str, char *ops);
char *my_eval_parenthesis(char **str, char *ops);
int my_check_priority(char c, char *ops);

char *my_cti_str(char **str);
int cti(char c);
char itc(int c);

int my_add_res(char nb1, char nb2, nb_s *calc, int i);
char my_add(char nb1, char nb2, nb_s *calc, int i);
void infinadd(char *nb1, char *nb2, nb_s *calc);
char *call_infinadd(char *nb1, char *nb2);
char *my_infinadd_pos_neg(char *nb1, char *nb2);

int my_sub_res(char nb1, char nb2, nb_s *calc, int i);
char my_sub(char nb1, char nb2, nb_s *calc, int i);
void infinsub(char *nb1, char *nb2, nb_s *calc);
char *call_infinsub(char *nb1, char *nb2);

char *call_infinmul(char *nb1, char *nb2);

char *infindiv(char *nb1, char *nb2);
char *infinmod(char *nb1, char *nb2);

int my_check_ops(char const *str, char *ops, bistro_s *bistro);
int my_check_av(char **av);
int who_is_bigger(char *nb1, char *nb2);
int my_check_num(char c);
int my_check_neg(char *nb1, char *nb2);
void my_check_ret(nb_s *calc, int *j);
void my_put_neg(nb_s *calc, int *j);
void my_put_neg_mul(nb_s *calc);

int my_strlen_no_space(char const *str);

char *my_delete_zero(char *str);
#endif
