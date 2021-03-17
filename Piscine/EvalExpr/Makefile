##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

FOLDER	=	./src/

TESTFOL	=	./tests/

TESTSRC =	$(TESTFOL)test_eval_expr.c		\

SRC	=	$(FOLDER)evalexpr.c			\
		$(FOLDER)func.c				\
		$(FOLDER)main.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

NAME	=	eval_expr

all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB) -g3
##		gcc -o $(CRINAME) $(OBJ) $(TESTSRC) $(LIB) $(CRITERION)

clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
