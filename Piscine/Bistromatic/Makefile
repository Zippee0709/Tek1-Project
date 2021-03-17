##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

FOLDER	=	./src/

TESTFOL	=	./tests/

TESTSRC =	$(TESTFOL)test_eval_expr.c		\

SRC	=      	$(FOLDER)main.c		\
		$(FOLDER)init.c		\
		$(FOLDER)func.c		\
		$(FOLDER)check.c	\
		$(FOLDER)check2.c	\
		$(FOLDER)space.c	\
		$(FOLDER)delete.c	\
		$(FOLDER)cti_itc.c	\
		$(FOLDER)eval_expr.c	\
		$(FOLDER)infinadd.c	\
		$(FOLDER)infinsub.c	\
		$(FOLDER)infinmul.c	\
		$(FOLDER)infindiv.c	\
		$(FOLDER)check_infin.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

NAME	=	calc

all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -g3 -o $(NAME) $(OBJ) $(LIB)
##		gcc -o $(CRINAME) $(OBJ) $(TESTSRC) $(LIB) $(CRITERION)

clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
