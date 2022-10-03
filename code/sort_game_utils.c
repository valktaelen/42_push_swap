/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:34:42 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/07 19:25:58 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swap the head of heaps if necesary
 * @param t_game *game The game
 * @return 1 if all is good, 0 else
 */
int	swap(t_game *game)
{
	t_stack	*head;
	t_stack	*head_1;

	if (game && game->a && game->a->next)
	{
		head = game->a->content;
		head_1 = game->a->next->content;
		if (head->nb > head_1->nb)
		{
			if (!swap_a(game))
				return (0);
		}
	}
	if (game && game->b && game->b->next)
	{
		head = game->b->content;
		head_1 = game->b->next->content;
		if (head->nb < head_1->nb)
		{
			if (!swap_b(game))
				return (0);
		}
	}
	return (1);
}

/**
 * Rotate the head of heaps if necesary
 * @param t_game *game The game
 * @param int force The heap that we absolutly wamt to rotate (LST_A or LST_B),
 * the other heap will rotate only if the rotate is necesary
 * @return 1 if all is good, 0 else
 */
int	rotate(t_game *game, int force)
{
	t_stack	*head;
	t_stack	*tail;

	if (game && ((game->a && game->a->next) || force == LST_A))
	{
		head = game->a->content;
		tail = ft_lstlast(game->a)->content;
		if (head->nb > tail->nb || force == LST_A)
		{
			if (!rotate_a(game))
				return (0);
		}
	}
	if (game && ((game->b && game->b->next) || force == LST_B))
	{
		head = game->b->content;
		tail = ft_lstlast(game->b)->content;
		if (head->nb < tail->nb || force == LST_B)
		{
			if (!rotate_b(game))
				return (0);
		}
	}
	return (1);
}

/**
 * Rotate (reverse) the tail of heaps if necesary
 * @param t_game *game The game
 * @param int force The heap that we absolutly wamt to rotate (LST_A or LST_B),
 * the other heap will rotate only if the rotate is necesary
 * @return 1 if all is good, 0 else
 */
int	rev_rotate(t_game *game, int force)
{
	t_stack	*head;
	t_stack	*tail;

	if (game && ((game->a && game->a->next) || force == LST_A))
	{
		head = game->a->content;
		tail = ft_lstlast(game->a)->content;
		if (head->nb > tail->nb || force == LST_A)
		{
			if (!rev_rotate_a(game))
				return (0);
		}
	}
	if (game && ((game->b && game->b->next) || force == LST_B))
	{
		head = game->b->content;
		tail = ft_lstlast(game->b)->content;
		if (head->nb < tail->nb || force == LST_B)
		{
			if (!rev_rotate_b(game))
				return (0);
		}
	}
	return (1);
}

static int	short_way_op_return(int rr, int rrr, int size)
{
	if (rrr == size && rr != 1)
		return (NOTHING);
	if (rr <= rrr)
	{
		if (rr == 0)
			return (PUSH);
		else if (rr == 1)
			return (SWAP);
		return (BEGIN);
	}
	return (END);
}

/**
 * For a list of t_stack, say if we need to do rotate or rev_rotate operation
 * to get the integer value that check with operation
 * @param t_list *list The list of t_stack
 * @param int op operation (inf, sup, eq)
 * @param int value Value to find
 * @return Return BEGIN if rotate is necessary, END if rev_rotate, SWAP
 * for swap or PUSH for push -- NOTHING if nothing to do.
 */
int	short_way_op(t_list *list, int op, int value)
{
	t_stack	*tmp;
	int		reverses[2];
	int		size;

	if (!list)
		return (NOTHING);
	reverses[0] = 0;
	size = ft_lstsize(list);
	reverses[1] = size;
	while (list)
	{
		tmp = list->content;
		if (check_op_cmp(tmp->nb, op, value))
		{
			reverses[1] = 0;
			if (reverses[1] == size)
				++reverses[0];
		}
		else if (reverses[1] == size)
			++reverses[0];
		else
			++reverses[1];
		list = list->next;
	}
	return (short_way_op_return(reverses[0], reverses[1], size));
}
