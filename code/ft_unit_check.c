/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:29:36 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/06 19:20:51 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Check if the list stack is sort
 * @return 1 if is sort,
 * 0 if not,
 * -1 if null / empty
 */
int	check_increasing_stack(t_list *stack, int len)
{
	t_list	*curent;
	t_list	*prec;
	t_stack	*cur_stack;
	t_stack	*prec_stack;

	if (!stack)
		return (-1);
	prec = stack;
	curent = stack;
	while (curent && len > 0)
	{
		prec_stack = prec->content;
		cur_stack = curent->content;
		if (prec_stack->nb > cur_stack->nb)
			return (0);
		prec = curent;
		curent = curent->next;
		--len;
	}
	return (1);
}

/**
 * Check if the list stack is sort
 * @return 1 if is sort,
 * 0 if not,
 * -1 if null / empty
 */
int	check_decreasing_stack(t_list *stack, int len)
{
	t_list	*curent;
	t_list	*prec;
	t_stack	*cur_stack;
	t_stack	*prec_stack;

	if (!stack)
		return (-1);
	prec = stack;
	curent = stack;
	while (curent && len > 0)
	{
		prec_stack = prec->content;
		cur_stack = curent->content;
		if (prec_stack->nb < cur_stack->nb)
			return (0);
		prec = curent;
		curent = curent->next;
		--len;
	}
	return (1);
}

/**
 * Check if the game is finish (sort complete)
 * @return 1 if finish, 0 else
 */
int	check_finish(t_game *game)
{
	if (check_increasing_stack(game->a, game->len_a) == 1
		&& check_increasing_stack(game->b, game->len_b) == -1)
		return (1);
	return (0);
}

/**
 * Check if the operations op1 = req1 and op2 = req2
 * @return 1 if they are equal, 0 else
 */
int	check_ops(char *op1, const char *req1, char *op2, const char *req2)
{
	if (0 == ft_strncmp(req1, (const char *)op1, ft_strlen(req1))
		&& 0 == ft_strncmp(req2, (const char *)op2, ft_strlen(req1)))
		return (1);
	return (0);
}

/**
 * Check if the operation is verify or not
 * @param int nb The number to compare
 * @param int op The operations to apply (bitwise) (<,>,==,<=,<=)
 * @param int cmp The number that is compare
 * @return The result of the condition (nb op cmp)
 */
int	check_op_cmp(int nb, int op, int cmp)
{
	if ((op & INF) && (op & SUP))
		return (1);
	if ((op & INF) && (op & EQ))
		return (nb <= cmp);
	if ((op & INF))
		return (nb < cmp);
	if ((op & SUP) && (op & EQ))
		return (nb >= cmp);
	if ((op & SUP))
		return (nb > cmp);
	if (op & EQ)
		return (nb == cmp);
	return (0);
}
