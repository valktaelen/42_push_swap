# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 20:38:51 by aartiges          #+#    #+#              #
#    Updated: 2022/10/03 23:25:40 by aartiges         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c		parser.c		ft_free.c			ft_alloc.c		\
		ft_op_push.c	ft_op_rotate.c	ft_op_rev_rotate.c	ft_op_swap.c	\
		ft_unit_check.c	ft_op.c			ft_op_optimisation.c				\
		sort_game.c		optimisation.c	sort_game_utils.c	parser_utils.c	\
		sort_short.c	sort_a.c		sort_b.c			offset.c		\
		ft_free2.c		\
		ft_debug.c

OBJS = ${SRCS:.c=.o}

HEADERS =	push_swap.h

LIBFT	=	libft/code

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o : %.c $(HEADERS)
	@${CC} ${CFLAGS} -c $< -o $@

all: 		${NAME}

libft_rule:
	@make -C $(LIBFT) bonus

$(NAME):	$(OBJS) libft_rule
			@echo "Compilation push_swap project"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a

clean:
			@echo "clean push_swap project"
			@make -C $(LIBFT) clean
			@${RM} ${OBJS}

fclean:
			@echo "fclean push_swap project"
			@make -C $(LIBFT) fclean
			@${RM} ${OBJS} ${NAME}

re: fclean all
