##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

FOLDER	=	./src/

SRC	= 	$(FOLDER)main.c			\
		$(FOLDER)set.c			\
		$(FOLDER)get.c			\
		$(FOLDER)run.c			\
		$(FOLDER)clock.c		\
		$(FOLDER)check.c		\
		$(FOLDER)event.c		\
		$(FOLDER)create.c		\
		$(FOLDER)mouse.c		\
		$(FOLDER)display.c		\
		$(FOLDER)window.c		\
		$(FOLDER)destroy.c		\
		$(FOLDER)basic_func.c		\


OBJ	=	$(SRC:.c=.o)

GRAPHIC	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

NAME	=	my_runner

all	:	$(OBJ)
		gcc $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(GRAPHIC)

clean 	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY 	:	all clean fclean re
