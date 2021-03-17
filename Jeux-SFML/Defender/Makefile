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
		$(FOLDER)init2.c		\
		$(FOLDER)my_help.c		\
		$(FOLDER)event.c		\
		$(FOLDER)run.c			\
		$(FOLDER)set.c			\
		$(FOLDER)get.c			\
		$(FOLDER)map.c			\
		$(FOLDER)draw.c			\
		$(FOLDER)draw2.c		\
		$(FOLDER)rect.c			\
		$(FOLDER)dlist.c		\
		$(FOLDER)dlist2.c		\
		$(FOLDER)convert.c		\
		$(FOLDER)free.c			\
		$(FOLDER)free2.c		\
		$(FOLDER)create.c		\
		$(FOLDER)create2.c		\
		$(FOLDER)collision.c		\
		$(FOLDER)move_sprite.c		\
		$(FOLDER)update.c		\
		$(FOLDER)update_tower.c		\
		$(FOLDER)game_check.c		\
		$(FOLDER)check_map.c		\
		$(FOLDER)check_func.c		\
		$(FOLDER)check_tower.c		\
		$(FOLDER)basic_func.c		\
		$(FOLDER)basic_func2.c		\
		$(FOLDER)create_window.c	\
		$(FOLDER)manage_mouse.c		\
		$(FOLDER)manage_pause.c		\

OBJ	=	$(SRC:.c=.o)			\
		$(MAIN:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3

CPPFLAGS +=	-Iinclude

GRAPHIC =        -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB	=	-L ./lib -lmy

NAME	=	my_defender

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(MAIN) $(SRC) $(GRAPHIC)
## 		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(LIB) $(CRITERION)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
