/*
** EPITECH PROJECT, 2018
** evalexpr.h
** File description:
** evalexpr.h
*/

#ifndef EVALEXPR_H
#define EVALEXPR_H

int eval_expr(char *str);
char *my_del_space(char *str);
int my_cti_double(char **str);

int my_check_priority(char c);
int my_calc_parenthesis(char **str);
int my_eval_wp(char **str);
int my_eval_np(char **str);
#endif
