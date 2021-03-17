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

SRC	=	$(FOLDER)alloc_map.c		\
		$(FOLDER)pos_max.c            	\
		$(FOLDER)go_back.c         	\
		$(FOLDER)find_path.c         	\
		$(FOLDER)check_star.c         	\
		$(FOLDER)check_next.c         	\
		$(FOLDER)change_flag.c         	\

OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

NAME	=	solver

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
