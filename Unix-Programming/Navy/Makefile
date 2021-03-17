##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	src/read_pos.c\
	src/player_one.c\
	src/player_two.c\
	src/fill_map.c\
	src/update.c\
	src/game.c\
	src/init.c\
	src/print_map.c\
	src/catch_signal.c\
	src/check_status_game.c\
	src/catch_hit_missed.c\
	src/start_game.c\
	src/sent_signal.c\
	src/read_pos2.c\

MAIN = src/main.c

LIB = 	-L./lib/my -lmy

HPATH =	include/

CFLAGS += -Wextra -Wall -Werror -g3 -I$(HPATH)

CRIT = tests/test_function.c

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

CRIT_NAME = criterion

NAME =	navy

all:	$(NAME)

$(NAME)	:	$(OBJ)
	@make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

tests_run:
	gcc -o $(CRIT_NAME) $(SRC) -I$(HPATH) $(CRIT) --coverage -lcriterion $(LIB)
	./$(CRIT_NAME)

clean:
	rm -f $(OBJ)
	@make clean -C lib/my

fclean:	clean
	rm -f $(NAME)
	rm -f $(CRIT_NAME)
	@make fclean -C lib/my

re:	fclean all
	@make re -C lib/my
.PHONY:	all clean fclean re
