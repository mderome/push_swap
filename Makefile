# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderome <mderome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 13:51:15 by mderome           #+#    #+#              #
#    Updated: 2021/12/25 14:49:40 by mderome          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT= ./libft/
HEADER_PATH = ./includes/
SRC_PATH = ./src/
SRC =	push_swap.c			\
		check.c				\
		a_operator.c		\
		b_operator.c		\
		algo_choice.c		\
		utils.c				\
		algo_for_5.c		\
		push_op.c			\
		rotate_op.c			\
		swap_op.c			\
		algo_for_all.c		\
		op_3_4.c			\
		choice_op.c			\
		find_better_moove.c	\

SRC_BASENAME = $(addprefix $(SRC_PATH), $(SRC))
CC =	gcc
CFLAGS = -Wall -Wextra -Werror -I $(HEADER_PATH) -I $(LIBFT)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC_BASENAME:.c=.o)

all :	$(NAME)

$(NAME) : 	$(OBJ) $(HEADER_PATH)
			make -C $(LIBFT)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft

clean :
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean :	clean
			make fclean -C $(LIBFT)
			rm -rf $(NAME)

re : fclean all
