/*
** EPITECH PROJECT, 2019
** test_my_strlen.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_strlen_nb_word(char const *str, char c);
int my_strlen_size_word(char const *str, int *i, char c);
char **my_str_to_word_tab(char const *str, char c);

Test(my_strlen_nb_word, test_nb_word)
{
    char const *str = "Hello how are you\n";
    int i = my_strlen_nb_word(str, ' ');

    cr_assert_eq(i, 4);
    cr_log_warn("my_strlen_nb_word, test number of word SUCCESS\n");
}

Test(my_strlen_size_word, test_size_word)
{
    char const *str = "Hello how are you";
    int i = 0;
    int size = 0;
    
    size = my_strlen_size_word(str, &i, ' ');
    cr_assert_eq(size, 5);
    cr_log_warn("my_strlen_nb_word, test size of word 'hello' SUCCESS\n");
    i = i + 1;
    size = my_strlen_size_word(str, &i, ' ');
    cr_assert_eq(size, 3);
    i = i + 1;
    cr_log_warn("my_strlen_nb_word, test size of word 'how' SUCCESS\n");
    size = my_strlen_size_word(str, &i, ' ');
    cr_assert_eq(size, 3);
    i = i + 1;
    cr_log_warn("my_strlen_nb_word, test size of word 'are' SUCCESS\n");
    size = my_strlen_size_word(str, &i, ' ');
    i = i + 1;
    cr_assert_eq(size, 3);
    cr_log_warn("my_strlen_nb_word, test size of word 'you' SUCCESS\n");
}

Test(my_str_to_word_tab, test_str_word_tab_if_have_correct_char)
{
    char const *str = "Hello how are you";
    char **tab = my_str_to_word_tab(str, ' ');
    int i = 0;

    while (tab[i] != NULL) {
        if (i == 0) {
            cr_assert_str_eq(tab[i], "Hello");
            cr_log_warn("my_str_to_word_tab, check 'hello' SUCCESS\n");
        }
        else if (i == 1) {
            cr_assert_str_eq(tab[i], "how");
            cr_log_warn("my_str_to_word_tab, check 'how' SUCCESS\n");
        }
        else if (i == 2) {
            cr_assert_str_eq(tab[i], "are");
            cr_log_warn("my_str_to_word_tab, check 'are' SUCCESS\n");
        }
        else if (i == 3) {
            cr_assert_str_eq(tab[i], "you");
            cr_log_warn("my_str_to_word_tab, check 'you' SUCCESS\n");
        }
        i = i + 1;
    }
}
