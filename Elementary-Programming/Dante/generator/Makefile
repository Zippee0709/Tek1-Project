##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for
##

TESTFOLDER =	./tests/

TESTSRC	=	$(TESTFOLDER)test_my_strlen.c	\

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

FOLDER  =	./src/

MAIN	=	$(FOLDER)main.c			\

SRC	=	$(FOLDER)init.c			\
		$(FOLDER)init_direction.c	\
		$(FOLDER)check.c		\
		$(FOLDER)check_neighbour.c	\
		$(FOLDER)set.c			\
		$(FOLDER)gen.c			\
		$(FOLDER)get.c			\
		$(FOLDER)dlist.c		\
		$(FOLDER)error.c		\
		$(FOLDER)print.c		\
		$(FOLDER)my_strcmp.c		\
		$(FOLDER)random_neighbour.c			\
		$(FOLDER)free.c			\

OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

NAME	=	generator

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

tests_run :
		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(CRITERION)
		./unit_tests
		gcov -b --exclude-directories tests/
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
