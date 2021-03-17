##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME =	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c *.c
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
