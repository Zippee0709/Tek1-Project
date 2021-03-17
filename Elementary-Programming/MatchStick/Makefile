##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for matchstick
##

TESTFOLDER =	./tests/test_map.c		\

FOLDER  =	./src/

SRC	=	$(FOLDER)main.c 		\
		$(FOLDER)ai.c			\
		$(FOLDER)get.c			\
		$(FOLDER)pow.c			\
		$(FOLDER)init.c			\
		$(FOLDER)take.c			\
		$(FOLDER)free.c			\
		$(FOLDER)error.c		\
		$(FOLDER)check.c		\
		$(FOLDER)search.c		\
		$(FOLDER)print.c		\
		$(FOLDER)print2.c		\
		$(FOLDER)matchstick.c		\
		$(FOLDER)fill_tab.c		\
		$(FOLDER)get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

NAME	=	matchstick

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
