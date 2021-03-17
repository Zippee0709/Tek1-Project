/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** check if a word is in the text
*/

int my_strstr_flw(char *text, char *word, int i)
{
    for (int j = 0; word[j] != '$'; j++, i++) {
        if (text[i] != word[j])
            return (-1);
    }
    return (0);
}

int my_strstr(char *text, char *word)
{
    int is_here = 0;
    int i_copy = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == word[0]) {
            i_copy = i;
            if (my_strstr_flw(text, word, i_copy) == 0)
                return (0);
        }
    }
    return (-1);
}
