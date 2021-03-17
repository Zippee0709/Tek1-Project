##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for do_op.c
##

FOLDER	=	./

SRC	=	$(FOLDER)do_op.c	\
		$(FOLDER)func.c		\
		$(FOLDER)main.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS 	=	-W -Wall -Wextra

CPPFLAGS +=	-I../include/

LIB	=	-L../lib -lmy

NAME	=	do-op

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re 
