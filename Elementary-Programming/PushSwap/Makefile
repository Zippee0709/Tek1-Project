##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for pushswap
##

TESTFOLDER =	./tests/test_my_sokoban.c		\

FOLDER  =	./src/

SRC	=	$(FOLDER)main.c 			\
		$(FOLDER)init.c				\
		$(FOLDER)list.c				\
		$(FOLDER)add_list.c			\
		$(FOLDER)pushswap.c			\
		$(FOLDER)manage_list.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

NCURSES =	-l ncurses

LIB	=	-L ./lib -lmy $(NCURSES)

CRITERION =	--coverage -lcriterion

NAME	=	my_pushswap

CRINAME =	unit_tests

all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(SRC) $(LIB)
##		gcc $(CPPFLAGS) -o $(CRINAME) $(SRC) $(TESTFOLDER) $(LIB) $(CRITERION)

clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
