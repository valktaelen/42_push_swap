/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:03:17 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/01 02:34:40 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * shift down all elements of stack a by 1. The last element
 * becomes the first one
 * @return 0 if there is an error, 1 else
 */
int	rev_rotate_a(t_game *game)
{
	t_list	*elem;
	t_list	*prec;

	if (game->len_a > 1)
	{
		elem = game->a;
		while (elem->next)
		{
			prec = elem;
			elem = elem->next;
		}
		prec->next = NULL;
		elem->next = game->a;
		game->a = elem;
		return (add_history(game, "rra"));
	}
	return (1);
}

/**
 * shift down all elements of stack b by 1. The last element
 * becomes the first one
 * @return 0 if there is an error, 1 else
 */
int	rev_rotate_b(t_game *game)
{
	t_list	*elem;
	t_list	*prec;

	if (game->len_b > 1)
	{
		elem = game->b;
		while (elem->next)
		{
			prec = elem;
			elem = elem->next;
		}
		prec->next = NULL;
		elem->next = game->b;
		game->b = elem;
		return (add_history(game, "rrb"));
	}
	return (1);
}

/**
 * rra and rrb at the same time
 * @return 0 if there is an error, 1 else
 */
int	rev_rotate_a_b(t_game *game)
{
	if (rev_rotate_a(game) && rev_rotate_b(game))
		return (1);
	return (0);
}
