** EPITECH PROJECT, 2018
** test_my_sokoban.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(my_searching_pos, check_p_pos)
{
    sokoban_s sokoban;

    sokoban.map = my_str_to_word_tab("##########\n"\
                                     "#        #\n"\
                                     "#        #\n"\
                                     "# PXO  ###\n"\
                                     "#        #\n"\
                                     "# OX     #\n"\
                                     "##########\n");
    my_searching_p(&sokoban, sokoban.map);
    cr_assert_eq(sokoban.x, 3);
    cr_assert_eq(sokoban.y, 2);
    my_free_word_tab(sokoban.map);
}

Test(move_left, check_mouv_left_func)
{
    sokoban_s sokoban;

    sokoban.map = my_str_to_word_tab("##########\n"\
                                     "#        #\n"\
                                     "#        #\n"\
                                     "# P    ###\n"\
                                     "#        #\n"\
                                     "#    XO  #\n"\
                                     "##########\n");
    move_left(&sokoban);
    my_searching_p(&sokoban, sokoban.map);
    cr_assert_eq(sokoban.x, 3);
    cr_assert_eq(sokoban.y, 1);
    my_free_word_tab(sokoban.map);
}

Test(move_right, check_mouv_right_func)
{
    sokoban_s sokoban;

    sokoban.map = my_str_to_word_tab("##########\n"\
                                     "#        #\n"\
                                     "#        #\n"\
                                     "# P    ###\n"\
                                     "#        #\n"\
                                     "#    XO  #\n"\
                                     "##########\n");
    move_right(&sokoban);
    my_searching_p(&sokoban, sokoban.map);
    cr_assert_eq(sokoban.x, 3);
    cr_assert_eq(sokoban.y, 3);
    my_free_word_tab(sokoban.map);
}

Test(move_up, check_mouv_up_func)
{
    sokoban_s sokoban;

    sokoban.map = my_str_to_word_tab("##########\n"\
                                     "#        #\n"\
                                     "#        #\n"\
                                     "# P    ###\n"\
                                     "#        #\n"\
                                     "#    XO  #\n"\
                                     "##########\n");
    move_up(&sokoban);
    my_searching_p(&sokoban, sokoban.map);
    cr_assert_eq(sokoban.x, 2);
    cr_assert_eq(sokoban.y, 2);
    my_free_word_tab(sokoban.map);
}

Test(move_down, check_mouv_down_func)
{
    sokoban_s sokoban;

    sokoban.map = my_str_to_word_tab("##########\n"\
                                     "#        #\n"\
                                     "#        #\n"\
                                     "# P    ###\n"\
                                     "#        #\n"\
                                     "#    XO  #\n"\
                                     "##########\n");
    move_down(&sokoban);
    my_searching_p(&sokoban, sokoban.map);
    cr_assert_eq(sokoban.x, 4);
    cr_assert_eq(sokoban.y, 2);
    my_free_word_tab(sokoban.map);
}

Test(my_count_x, count_nb_x)
{
    sokoban_s sokoban;

    sokoban.nb_x = my_count_x("##########\n"\
                             "#        #\n"\
                             "#        #\n"\
                             "# PXO  ###\n"\
                             "#        #\n"\
                             "# OX     #\n"\
                             "##########\n");

    cr_assert_eq(sokoban.nb_x, 2);
}
