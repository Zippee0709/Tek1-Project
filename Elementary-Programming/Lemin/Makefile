##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard src/*.c)	\
		$(wildcard src/utils/*.c)

NOMAIN	=	

NAME	=	lem_in

CRITNAME =	unit_test

CPPFLAGS +=	-I ./include -g3

CRITERION =	--coverage -lcriterion

LDFLAGS	=	-L ./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

TEST	=	./tests/test.c

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C ./lib/my/
		gcc -o $(NAME) $(SRC) $(LIB) $(LDFLAGS) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)
		rm -f $(TEMP)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)
		make fclean -C ./lib/my/

re	:	fclean all

.PHONY	:	all clean fclean re
