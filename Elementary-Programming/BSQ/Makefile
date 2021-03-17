##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

TESTFOLDER =	./tests/test_map.c		\

FOLDER  =	./src/

SRC	=	$(FOLDER)main.c 		\
		$(FOLDER)bsq.c	 		\
		$(FOLDER)bsq2.c 		\
		$(FOLDER)read.c 		\
		$(FOLDER)check_err.c 		\
		$(FOLDER)my_str_to_word_tab.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

NAME	=	bsq

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
