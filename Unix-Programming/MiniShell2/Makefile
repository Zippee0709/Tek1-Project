##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make project
##

FOLDER	=	./src/

MAIN 	=	$(FOLDER)main.c		\

MAIN_OBJ =	$(MAIN:.c=.o)

SRC 	=	$(FOLDER)init.c		\
		$(FOLDER)list.c		\
		$(FOLDER)func.c		\
		$(FOLDER)free.c		\
		$(FOLDER)shell.c	\
		$(FOLDER)getenv.c	\
		$(FOLDER)redirect.c	\
		$(FOLDER)set_env.c	\
		$(FOLDER)execution.c	\
		$(FOLDER)copy_env.c	\
		$(FOLDER)list_cmd.c	\
		$(FOLDER)parse_cmd.c	\
		$(FOLDER)clean_cmd.c	\
		$(FOLDER)check_cmd.c	\
		$(FOLDER)func_list.c	\
		$(FOLDER)clean_str.c	\
		$(FOLDER)array_tab.c	\
		$(FOLDER)str_concat.c	\
		$(FOLDER)get_file.c	\
		$(FOLDER)check_redirect.c	\
		$(FOLDER)change_directory.c	\

OBJ	=	$(SRC:.c=.o)

CRI_SRC	=	./tests/test.c		\

CFLAGS	=	-Wall -Wall -Wextra

CPPFLAGS +=	-I ./include

LIB	=	-L ./lib -lmy -lgnl

NAME	=	mysh

CRINAME =	unit_test

CRITERION =	-lcriterion --coverage

CC	=	gcc

all	:	$(NAME)

$(NAME)	:	$(MAIN_OBJ) $(OBJ)
		make -C ./lib/my
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LIB)

debug	:
		make -C ./lib/my
		$(CC) $(CFLAGS) $(CPPFLAGS) -g3 -o $(NAME) $(MAIN) $(SRC) $(LIB)
		valgrind --leak-check=full ./$(NAME)

tests_run :	$(OBJ)
		make -C ./lib/my/
		$(CC) -o $(CRINAME) $(OBJ) $(CRI_SRC) $(LIB) $(CRITERION)
		./unit_test
		gcovr -b --exclude-directories tests

clean	:
		rm -f $(OBJ)
		rm -f $(MAIN_OBJ)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)
		make fclean -C ./lib/my/

re	:	fclean all

.PHONY	:	all clean fclean re tests_run
