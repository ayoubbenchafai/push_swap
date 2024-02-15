NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = bonus/checker.c bonus/ft_split_bonus.c bonus/parsing1_utils_bonus.c  bonus/functions_utils1_bonus.c \
	bonus/functions_utils2_bonus.c bonus/functions_utils3_bonus.c bonus/functions_utils4_bonus.c \
	bonus/functions_utils5_bonus.c bonus/functions_utils6_bonus.c bonus/functions_utils7_bonus.c \
	bonus/functions_utils8_bonus.c bonus/functions_utils9_bonus.c bonus/functions_utils10_bonus.c \
	bonus/gnl_utils_bonus.c bonus/get_next_line_bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME_B)

$(NAME_B): $(OBJ) bonus/checker_bonus.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME_B)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_B)

re: fclean all

.PHONY: clean fclean re all
