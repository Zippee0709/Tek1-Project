##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for infinadd
##

TESTFOLDER =	./tests/

CRISRC	=	$(TESTFOLDER)test_my_printf.c	\
		$(TESTFOLDER)test_my_printf1.c	\

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

LIB	=	-L ./ -lmy

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

NAME	=	sum_stdarg

all	:
		make -C lib/my
		gcc -o $(CRINAME) $(CRISRC) $(LIB) $(CRITERION)

clean	:
		make clean -C lib/my

fclean	:	clean
		rm -f $(CRINAME)
		make fclean -C lib/my

re	:	fclean all

.PHONY	:	all clean fclean re
