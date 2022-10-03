/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:52:00 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/01 00:02:24 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * shift up all elements of stack a by 1. The first element becomes
 * the last one
 * @return 0 if there is an error, 1 else
 */
int	rotate_a(t_game *game)
{
	t_list	*elem;

	if (game->len_a > 1)
	{
		elem = game->a;
		game->a = elem->next;
		elem->next = NULL;
		ft_lstadd_back(&(game->a), elem);
		return (add_history(game, "ra"));
	}
	return (1);
}

/**
 * shift up all elements of stack b by 1. The first element becomes
 * the last one
 * @return 0 if there is an error, 1 else
 */
int	rotate_b(t_game *game)
{
	t_list	*elem;

	if (game->len_b > 1)
	{
		elem = game->b;
		game->b = elem->next;
		elem->next = NULL;
		ft_lstadd_back(&(game->b), elem);
		return (add_history(game, "rb"));
	}
	return (1);
}

/**
 * ra and rb at the same time
 * @return 0 if there is an error, 1 else
 */
int	rotate_a_b(t_game *game)
{
	if (rotate_a(game) && rotate_b(game))
		return (1);
	return (0);
}
