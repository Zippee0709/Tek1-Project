##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/main.c		\
		src/duplicate_env.c	\
		src/treat_buf.c		\
		src/modify_env.c	\
		src/cd.c		\
		src/check_sign.c	\
		src/setenv.c		\
		src/unsetenv.c		\
		src/redirect.c          \
		src/check_redirect.c    \
		src/error_management.c	\
		src/my_strspecialcpy.c	\
		src/free.c              \
		src/dlist.c             \
		src/leave.c		\
		src/main_shell.c	\
		src/get_size_with_stat.c\
		src/do_env.c		\

NOMAIN	=	tests/test.c		\
		src/duplicate_env.c	\
		src/treat_buf.c		\
		src/modify_env.c	\
		src/cd.c		\
		src/check_sign.c	\
		src/setenv.c		\
		src/unsetenv.c		\
		src/redirect.c          \
		src/check_redirect.c    \
		src/error_management.c	\
		src/my_strspecialcpy.c	\
		src/free.c              \
		src/dlist.c             \
		src/leave.c		\
		src/main_shell.c	\
		src/get_size_with_stat.c\
		src/do_env.c		\

CC	=	cc

NAME	=	42sh

CRITNAME =	unit_test

CPPFLAGS =	-I ./include

CFLAGS	+=	-Wall -Werror -Wextra

CRITERION =	-lcriterion --coverage

LDFLAGS	=	-L ./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

OBJ_TEST=	$(NOMAIN:.c=.o)

TEST	=	./tests/test.c

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C ./lib/my/
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

tests_run:	$(OBJ)
		make -C ./lib/my/
		gcc -o $(CRITNAME) $(NOMAIN) $(CRITERION) $(CPPFLAGS) $(LDFLAGS)
		./unit_test

debug	:	CFLAGS += -g3
debug	:	re

clean	:
		rm -f $(OBJ)
		rm -f $(TEMP)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)
		make fclean -C ./lib/my/
re	:	fclean all

.PHONY	:	all clean fclean re
