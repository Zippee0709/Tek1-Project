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
		$(FOLDER)error.c		\
		$(FOLDER)malloc.c		\
		$(FOLDER)get.c			\
		$(FOLDER)math.c			\
		$(FOLDER)func.c			\
		$(FOLDER)trigo.c		\
		$(FOLDER)calc_fun.c		\
		$(FOLDER)my_strcmp.c		\
		$(FOLDER)free.c			\


OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-lm

NAME	=	108trigo

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB)
## 		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(LIB) $(CRITERION)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
