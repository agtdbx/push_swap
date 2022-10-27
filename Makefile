# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 10:46:18 by aderouba          #+#    #+#              #
#    Updated: 2022/10/27 16:15:39 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c \
		params.c \
		ft_printf.c \
		ft_utils.c \
		ft_utils2.c \
		print_fd.c \
		str_utils.c \
		str_utils2.c \
		nbr_utils.c \
		stack_utils.c \
		stack_swap.c \
		stack_push.c \
		stack_rotate.c \
		stack_reverse_rotate.c \
		sort_utils.c \
		little_sort.c \
		sort.c


OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
