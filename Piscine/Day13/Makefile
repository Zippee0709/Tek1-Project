##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for do_op.c
##

FOLDER	=	./

SRC	=	$(FOLDER)windows.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS 	=	-W -Wall -Wextra

CPPFLAGS +=	-I../include/

LIB	=	-L../lib -lmy

NAME	=	window

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) -l c_graph_prog

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re 
