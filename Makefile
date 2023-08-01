# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 07:28:34 by jhogonca          #+#    #+#              #
#    Updated: 2023/07/28 07:28:34 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRC =	srcs/main.c srcs/init_stack.c srcs/utils.c srcs/ft_split.c \
		srcs/push_or_swap.c srcs/reverse_or_rotate.c \
		srcs/sort_over_five.c srcs/sort_under_five.c srcs/init_utils.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
HEADER = srcs/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@printf "\033[0;31mRunning Norminette...\033[0m\n"
	@norminette $(HEADER)
	@norminette $(SRC)

leak: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re norm


