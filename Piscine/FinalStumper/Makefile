##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for rush3
##

FOLDER	=	./src/

TESSRC	=	./tests/test_rush3.c	\

CRITERION =	--coverage -lcriterion

CNAME	=	unit_test

SRC	=	$(FOLDER)main.c		\
		$(FOLDER)func.c		\
		$(FOLDER)my_put_nbr.c	\
		$(FOLDER)line.c		\
		$(FOLDER)error.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS +=	-Iinclude

NAME	=	rush3

CFLAGS	=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(CNAME) $(SRC) $(TESSRC) $(CRITERION)

clean	:
		rm -f $(FOLDER)$(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
