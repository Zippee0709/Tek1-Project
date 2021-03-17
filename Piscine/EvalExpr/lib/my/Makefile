##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for compile lib
##

FOLDER	=	./

SRC	=	$(FOLDER)my_putchar.c				\
		$(FOLDER)my_putchar_err.c			\
		$(FOLDER)my_isneg.c				\
		$(FOLDER)my_put_nbr.c				\
		$(FOLDER)my_swap.c				\
		$(FOLDER)my_putstr.c				\
		$(FOLDER)my_putstr_err.c			\
		$(FOLDER)my_strlen.c				\
		$(FOLDER)my_getnbr.c				\
		$(FOLDER)my_sort_int_array.c			\
		$(FOLDER)my_compute_power_rec.c			\
		$(FOLDER)my_compute_square_root.c		\
		$(FOLDER)my_is_prime.c				\
		$(FOLDER)my_find_prime_sup.c			\
		$(FOLDER)my_strcpy.c				\
		$(FOLDER)my_strncpy.c				\
		$(FOLDER)my_revstr.c				\
		$(FOLDER)my_strstr.c				\
		$(FOLDER)my_strcmp.c				\
		$(FOLDER)my_strncmp.c				\
		$(FOLDER)my_strupcase.c				\
		$(FOLDER)my_strlowcase.c			\
		$(FOLDER)my_strcapitalize.c			\
		$(FOLDER)my_str_isalpha.c			\
		$(FOLDER)my_str_isnum.c				\
		$(FOLDER)my_str_islower.c			\
		$(FOLDER)my_str_isupper.c			\
		$(FOLDER)my_str_isprintable.c			\
		$(FOLDER)my_showstr.c				\
		$(FOLDER)my_showmem.c				\
		$(FOLDER)my_strcat.c				\
		$(FOLDER)my_strncat.c				\
		$(FOLDER)my_strdup.c				\
		$(FOLDER)my_str_to_word_array.c			\
		$(FOLDER)my_show_word_array.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
