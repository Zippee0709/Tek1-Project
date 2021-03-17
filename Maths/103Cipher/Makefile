##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

TESTFOLDER =	./tests/test_my_cipher.c	\

FOLDER  =	./src/

TESTSRC =	$(FOLDER)init.c			\
		$(FOLDER)func.c			\
		$(FOLDER)calc.c			\
		$(FOLDER)matrix.c		\
		$(FOLDER)my_getnbr.c		\

SRC	=	$(FOLDER)main.c 		\
		$(FOLDER)init.c			\
		$(FOLDER)func.c			\
		$(FOLDER)calc.c			\
		$(FOLDER)matrix.c		\
		$(FOLDER)my_getnbr.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

NAME	=	103cipher

CRINAME =	unit_tests

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)
		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(TESTFOLDER) $(CRITERION)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
