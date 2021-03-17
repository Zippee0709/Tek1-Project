##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make the lib
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

.PHONY:	all clean fclean re
