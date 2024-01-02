.SILENT:

NAME = push_swap
NAME_BONUS = checker

CC = cc

SRC = srcs/init_stack.c srcs/utils.c srcs/ft_split.c \
	srcs/push_or_swap.c srcs/reverse_or_rotate.c srcs/inutils.c \
	srcs/sort_list.c srcs/sort_utils.c srcs/set_cust.c

SRC_BONUS = srcs/checker.c

MAIN_OBJ = srcs/main.o

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
HEADER = srcs/push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS) $(MAIN_OBJ) # Include the main object file in clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

norm:
	@printf "\033[0;31mRunning Norminette...\033[0m\n"
	@norminette $(HEADER)
	@norminette $(SRC)

leak: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re norm
