##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

TESTFOLDER =	./tests/test_my_sokoban.c		\

FOLDER  =	./src/

MAIN	=	$(FOLDER)main.c				\

SRC	=	$(FOLDER)read.c				\
		$(FOLDER)game.c				\
		$(FOLDER)func.c				\
		$(FOLDER)check.c			\
		$(FOLDER)sokoban.c			\
		$(FOLDER)my_swap.c			\
		$(FOLDER)move_func.c			\
		$(FOLDER)move_func2.c			\
		$(FOLDER)my_str_to_word_tab.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

NCURSES =	-l ncurses

LIB	=	-L ./lib -lmy $(NCURSES)

CRITERION =	--coverage -lcriterion

NAME	=	my_sokoban

CRINAME =	unit_tests

all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LIB)
		gcc $(CPPFLAGS) -o $(CRINAME) $(OBJ) $(TESTFOLDER) $(LIB) $(CRITERION)

clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
