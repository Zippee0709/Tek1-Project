##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 101pong
##

CC	=	cc

RM	=	rm -f

SRC	=	101pong.c \

NAME	=	101pong

OBJS	=	$(SRC:.c=.o)

LIBC	=	-L./lib/my

CPPFLAGS	+=	-I./include

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(FLAG) $(LIBC) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
