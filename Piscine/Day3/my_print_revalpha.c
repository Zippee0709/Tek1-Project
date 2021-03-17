/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** write function display z to a in descending order
*/

void	my_putchar(char c);

int my_print_revalpha(void)
{
    char l = 'z';
    
    while (l >= 'a') {
	my_putchar(l);
	l = l - 1;
    }
    return (0);
}
