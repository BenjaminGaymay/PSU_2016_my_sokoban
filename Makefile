##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
## 
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
## 
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Thu Dec 15 17:26:11 2016 Benjamin GAYMAY
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_sokoban

CFLAGS	+=	-I./include

SRCS	=	main.c \
		my_putstr.c \
		my_putchar.c \
		my_puterror.c \
		my_strcat.c \
		my_strlen.c \
		count.c \
		use_array.c \
		my_sokoban.c \
		create_map.c \
		aff_map.c \
		game_over.c \
		moves.c \
		can_i_move.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
