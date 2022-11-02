# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 10:46:18 by aderouba          #+#    #+#              #
#    Updated: 2022/10/28 13:52:11 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC = 	src/push_swap.c \
		src/params.c \
		src/ft_printf.c \
		src/ft_utils.c \
		src/ft_utils2.c \
		src/print_fd.c \
		src/str_utils.c \
		src/str_utils2.c \
		src/nbr_utils.c \
		src/stack_utils.c \
		src/stack_swap.c \
		src/stack_push.c \
		src/stack_rotate.c \
		src/stack_reverse_rotate.c \
		src/sort_utils.c \
		src/little_sort.c \
		src/sort.c

SRC_BONUS = 	src_bonus/checker_bonus.c \
				src_bonus/params_bonus.c \
				src_bonus/ft_printf_bonus.c \
				src_bonus/ft_utils_bonus.c \
				src_bonus/ft_utils2_bonus.c \
				src_bonus/print_fd_bonus.c \
				src_bonus/str_utils_bonus.c \
				src_bonus/str_utils2_bonus.c \
				src_bonus/nbr_utils_bonus.c \
				src_bonus/stack_utils_bonus.c \
				src_bonus/stack_swap_bonus.c \
				src_bonus/stack_push_bonus.c \
				src_bonus/stack_rotate_bonus.c \
				src_bonus/stack_reverse_rotate_bonus.c \
				src_bonus/sort_utils_bonus.c \
				src_bonus/sort_bonus.c \
				src_bonus/get_next_line_bonus.c \
				src_bonus/get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean $(NAME)

bonus : $(NAME_BONUS)

.PHONY: all clean fclean re bonus
