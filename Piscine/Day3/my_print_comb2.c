/*
** EPITECH PROJECT, 2018
** my_print_comb2.c
** File description:
** same work to my_print_comb but with 00, 01
*/

void	my_putchar(char c);

void my_putchar_comb2(char a, char b, char c, char d)
{
    if ((a == '9') && (b == '8') && (c == '9') && (d == '9')) {
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    }
    else {
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    my_putchar(',');
    my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    char a = '0';
    char b = '0';
    char c = '0';
    char d = '1';

    while (a <= '9') {
	while (b <= '9') {
            while (c <= '9') {
		while (d <= '9') {
                    if (a == c && b == d)
                        d = d + 1;
                    my_putchar_comb2(a, b, c, d);
		    d = d + 1;
		}
		c = c + 1;
                d = '0';
	    }
	    b = b + 1;
            c = a;
            d = b + 1;
	}
	a = a + 1;
	b = '0';
    }
    return (0);
}
