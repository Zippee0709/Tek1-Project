/*
** EPITECH PROJECT, 2018
** my_print_digits.c
** File description:
** function display 1 to 9 in acending order
*/

void	my_putchar(char c);

int my_print_digits(void)
{
    char n = '0';
    
    while (n <= '9') {
	my_putchar(n);
	n = n + 1;
    }
    return (0);
}
