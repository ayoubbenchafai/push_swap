NAME_M = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c stack.c ft_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME_M)

$(NAME_M): $(OBJ) push_swap.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME_M)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_M)

re: fclean all

.PHONY: clean fclean re all
