##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for
##

TESTFOLDER =	./tests/

TESTSRC	=	$(TESTFOLDER)test.c

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

FOLDER  =	./src/

MAIN	=	$(FOLDER)main.c			\

SRC	=	$(FOLDER)init.c			\
		$(FOLDER)error.c		\
		$(FOLDER)func.c			\
		$(FOLDER)bombyx.c		\

OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)			\

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

NAME	=	106bombyx


all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

tests_run :
		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(CRITERION)
		./unit_tests
		gcovr -b --exclude-directories tests

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
