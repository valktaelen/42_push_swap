/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:07:05 by aartiges          #+#    #+#             */
/*   Updated: 2022/10/03 23:21:04 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/code/libft.h"

# define NOTHING -1
# define PUSH 0
# define SWAP 1
# define BEGIN 2
# define END 3
# define LST_A 1
# define LST_B 2
# define INF 0b1
# define SUP 0b10
# define EQ 0b100

// structures

/**
 * Structure that contain integer
 * @param int nb value of integer
 */
typedef struct s_stack
{
	int				nb;
}	t_stack;

/**
 * Structure that contain the game with the 2 stacks
 * @param t_list *a stack a
 * @param t_list *b stack b
 * @param int len_a length of a
 * @param int len_b length of b
 */
typedef struct s_game
{
	t_list	*a;
	t_list	*b;
	t_list	*steps;
	t_list	*offset_a;
	t_list	*offset_b;
	int		len_a;
	int		len_b;
	int		min;
	int		max;
}	t_game;

// Errors

void	fatal_error(char *message);

// Parser

int		has_double(t_game *game);
char	***split_args(char **params, int len);
char	*unsplit_args(char **argv, int argc);
t_game	*parser(char **params, int len);

// Free

void	free_game(t_game **game);
void	free_stack(void *stack);
void	*free_list_null(t_list **list, void (*del)(void *));
t_list	*free_one_get_next(t_list *lst);
void	free_split(char **split);
void	free_args(char ***args);
void	free_offset_head(t_list **lst);

// Allocation

t_list	*create_list(char **params, int len);
t_stack	*new_content(char *nb);
int		*create_offset(int offset);
t_list	*create_offset_list(int offset);
char	*str_join_free_s1(char *s1, char *s2);

// Operations

t_list	*get_new_hist(const char *history);
int		add_history(t_game *game, const char *history);
void	ft_print_op(t_game *game);
t_list	*remove_2_curents(t_list **lst, t_list *cur, t_list *prec);
t_list	*change_2_curents(t_list **l, t_list *cur, t_list *pre, const char *n);
void	ft_simplify_ops(t_list **hist);
int		swap_a(t_game *game);
int		swap_b(t_game *game);
int		swap_a_b(t_game *game);
int		push_a(t_game *game);
int		push_b(t_game *game);
int		push_b_on_a(t_game *game);
int		rotate_a(t_game *game);
int		rotate_b(t_game *game);
int		rotate_a_b(t_game *game);
int		rev_rotate_a(t_game *game);
int		rev_rotate_b(t_game *game);
int		rev_rotate_a_b(t_game *game);

// Check

int		check_decreasing_stack(t_list *stack, int len);
int		check_increasing_stack(t_list *stack, int len);
int		check_finish(t_game *game);
int		check_ops(char *op1, const char *req1, char *op2, const char *req2);
int		check_op_cmp(int nb, int op, int cmp);

// Optimisation

int		max_stack(t_list *lst, int cur_max);
int		min_stack(t_list *lst, int cur_min);
int		find_mid(t_list *list, int offset,
			int (*ext_stack)(t_list *lst, int curent));

// Sort utils

int		swap(t_game *game);
int		rotate(t_game *game, int force);
int		rev_rotate(t_game *game, int force);
int		short_way_op(t_list *list, int op, int value);

// Sort
int		sort_inf_4(t_game *game);
int		sort(t_game *game, int list, int direction, int (*push)(t_game *game),
			int *offset);
int		create_new_offset(t_list **offset, int new_offset);
int		clear_reverse(t_game *game, int list, int extrem);
int		sort_curent_partition_a(t_game *game);
int		sort_curent_partition_b(t_game *game);
int		*get_curent_offset(t_list *offset);
int		change_offset(t_game *game, int list_that_modify, int change);

int		sort_game(t_game *game);

#endif
