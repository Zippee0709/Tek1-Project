##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/free_tetris.c\
		src/debug/recup_tetriminos_data.c\
		src/debug/check_tetrimino.c	\
		src/debug/print_tetrimino_data.c	\
		src/debug/read_file.c	\
		src/debug/recup_argv.c\
		src/debug/do_debug_mode.c\
		src/debug/print_option.c\
		src/debug/recup_argv_flw.c\
		src/debug/wait_input.c\
		src/debug/count_occur.c\
		src/debug/print_help_message.c\
		src/game/game.c\
		src/game/event.c\
		src/game/init_game.c\
		src/game/init_forms.c\
		src/game/init_forms2.c\
		src/game/print_tetris.c\
		src/game/shape.c\
		src/game/check_shape.c\

OBJ	=	$(SRC:.c=.o)

LIB	= 	-L ./lib/my -lmy -lncurses

CC	=	gcc

NAME	=	tetris

CFLAGS	+=	-Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		make clean -C lib/my
		rm -f $(OBJ)

fclean: clean
		make fclean -C lib/my
		rm -f $(NAME)

re: fclean all
