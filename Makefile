NAME_M = push_swap
NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/push_swap.c mandatory/ft_split.c mandatory/parsing.c  mandatory/functions_utils1.c \
	mandatory/functions_utils2.c mandatory/functions_utils3.c mandatory/functions_utils4.c \
	mandatory/functions_utils5.c mandatory/functions_utils6.c mandatory/functions_utils7.c \
	mandatory/functions_utils8.c mandatory/functions_utils9.c mandatory/functions_utils10.c
SRCB = bonus/checker_bonus.c bonus/ft_split_bonus.c bonus/parsing_bonus.c  bonus/functions_utils1_bonus.c \
	bonus/functions_utils2_bonus.c bonus/functions_utils3_bonus.c bonus/functions_utils4_bonus.c \
	bonus/functions_utils5_bonus.c bonus/functions_utils6_bonus.c \
	bonus/gnl_utils_bonus.c bonus/get_next_line_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME_M)

$(NAME_M): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME_M)

bonus: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME_B)

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME_M) $(NAME_B)

re: fclean all

.PHONY: clean fclean re all
