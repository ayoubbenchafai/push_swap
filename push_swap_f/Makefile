NAME_M = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c ft_split.c parsing1_utils.c  functions_utils1.c \
	functions_utils2.c functions_utils3.c functions_utils4.c \
	functions_utils5.c functions_utils6.c functions_utils7.c \
	functions_utils8.c functions_utils9.c functions_utils10.c

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
