/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:54:20 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/30 23:40:37 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap the first 2 elements at the top of stack a. Do nothing if there
 * is only one or no elements
 * @return 0 if there is an error, 1 else
 */
int	swap_a(t_game *game)
{
	t_list	*first;

	if (game && game->len_a > 1)
	{
		first = game->a->next;
		game->a->next = first->next;
		first->next = game->a;
		game->a = first;
		return (add_history(game, "sa"));
	}
	return (1);
}

/**
 * swap the first 2 elements at the top of stack b. Do nothing if there
 * is only one or no elements
 * @return 0 if there is an error, 1 else
 */
int	swap_b(t_game *game)
{
	t_list	*first;

	if (game && game->len_b > 1)
	{
		first = game->b->next;
		game->b->next = first->next;
		first->next = game->b;
		game->b = first;
		return (add_history(game, "sb"));
	}
	return (1);
}

/**
 * sa and sb at the same time
 * @return 0 if there is an error, 1 else
 */
int	swap_a_b(t_game *game)
{
	if (swap_a(game) && swap_b(game))
		return (1);
	return (0);
}
