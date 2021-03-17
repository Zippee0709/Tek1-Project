##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rvf

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-Iinclude $(CSFML)

DFLAGS	=	-W -Wall -Wextra -pedantic

DIR	=	src/

EXTENSION	=	.c

FILES	=	$(addsuffix $(EXTENSION), main	\
		lib				\
		useful				\
		useful_fct			\
		random				\
		init				\
		map_gen				\
		map_proto			\
		menu_fct			\
		player_fct			\
		snow				\
		view				\
		objects				\
		load_maps			\
		create_menu			\
		display				\
		display_menu			\
		cursor				\
		screenshot			\
		inventory			\
		errors				\
		events				\
		enemies				\
		enemies_update			\
		button_scale			\
		pause_fct			\
		init_stat			\
		stat_update			\
		my_rpg				\
		transition			\
		loading				\
		destroy				\
		pnj				\
		quest				\
		convert				\
		display_stat			\
		global_pos			\
		shot				\
		player)

SRC	=	$(addprefix $(DIR),$(FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

debug:
	@$(CC) $(SRC) -g3 $(CFLAGS) -o $(NAME)#$(DFLAGS) $(CFLAGS) -o $(NAME)
	valgrind ./$(NAME)

clean :
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
