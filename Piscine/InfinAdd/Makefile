##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

FOLDER	=	./src/

SRC	=	$(FOLDER)infinadd.c		\
		$(FOLDER)infinsub.c		\
		$(FOLDER)my_put_func.c		\
		$(FOLDER)print_func.c		\
		$(FOLDER)func.c			\
		$(FOLDER)main.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

NAME	=	infin_add

all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB) -g3

clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
