/*
** EPITECH PROJECT, 2018
** my_print_comb.c
** File description:
** print 3  differents digits number in ascending order
*/
void	my_putchar(char c);

void	my_putchar_comb(char a, char b, char c)
{
    if ((a == '7' ) && (b == '8') && (c == '9')) {
	my_putchar(a);
	my_putchar(b);
	my_putchar(c);	
    }
    else {
	my_putchar(a);
	my_putchar(b);
	my_putchar(c);
	my_putchar(',');
	my_putchar(' ');
    }
}

int my_print_comb(void)
{
    char a = '0';
    char b = '1';
    char c = '2';

    while (a <= '7') {
	while (b <= '8') {
	    while (c <= '9') {
		my_putchar_comb(a, b, c);
		c = c + 1;
	    }
	    b = b + 1;
	    c = b + 1;
	}
	a = a + 1;
	b = a + 1;
	c = a + 2;	    
    }
    return (0);
}
