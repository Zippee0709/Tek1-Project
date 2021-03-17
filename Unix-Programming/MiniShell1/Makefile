##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for minishell
##

TESTFOLDER =	./tests/

TESTSRC	=	$(TESTFOLDER)test_my_strlen.c	\

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

FOLDER  =	./src/

MAIN	=	$(FOLDER)main.c			\

SRC	=	$(FOLDER)get.c			\
		$(FOLDER)free.c			\
		$(FOLDER)check.c		\
		$(FOLDER)malloc.c		\
		$(FOLDER)execution.c		\
		$(FOLDER)minishell.c		\
		$(FOLDER)my_env_cpy.c		\
		$(FOLDER)my_str_concat.c	\
		$(FOLDER)my_str_to_word_tab.c	\

OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

LIB	=	-L ./lib -lmy -lgnl

NAME	=	minishell


all	:	$(OBJ)
		make -C lib/my
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(SRC) $(MAIN) $(LIB)
		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(LIB) $(CRITERION)
clean	:
		rm -f $(OBJ)
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
