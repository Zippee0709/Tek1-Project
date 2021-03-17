/*
** EPITECH PROJECT, 2018
** My_print_alpha
** File description:
** a function who print a to z in acending order 
*/
void	my_putchar(char c);

int my_print_alpha(void)
{
    char letter = 'a';
    
    while (letter <= 'z') {
	my_putchar(letter);
        letter = letter + 1;
    }
    return (0);
}
