##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for intersection
##

TESTFOLDER =	./tests/test_my_cipher.c	\

FOLDER  =	./src/

TESTSRC =	$(FOLDER)init.c			\

SRC	=	$(FOLDER)forms.c		\
		$(FOLDER)intersection.c		\
		$(FOLDER)my_str_isnum.c		\
		$(FOLDER)main.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy

CRITERION =	--coverage -lcriterion

NAME	=	104intersection

CRINAME =	unit_tests

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) -lm
##		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(TESTFOLDER) $(CRITERION)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
