##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	$(wildcard src/*.c)		\
		$(wildcard menu/*.c)	\
		$(wildcard game/*.c)	\

OBJ	=	$(SRC:.c=.o)			\

NAME	=	my_defender

CFLAGS	=	-I./include/ -g -Wall -Wextra

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) *~
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.Phony: all clean fclean re