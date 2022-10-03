/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:33:35 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/08 15:27:35 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Take the first element at the top of b and put it at the top of a. Do
 * nothing if b is empty
 * @return 0 if there is an error, 1 else
 */
int	push_a(t_game *game)
{
	t_list	*elem;

	if (game->len_b > 0)
	{
		elem = game->b;
		game->b = elem->next;
		elem->next = NULL;
		ft_lstadd_front(&(game->a), elem);
		game->len_a = game->len_a + 1;
		game->len_b = game->len_b - 1;
		return (add_history(game, "pa"));
	}
	return (1);
}

/**
 * Take the first element at the top of a and put it at the top of b. Do
 * nothing if a is empty
 * @return 0 if there is an error, 1 else
 */
int	push_b(t_game *game)
{
	t_list	*elem;

	if (game->len_a > 0)
	{
		elem = game->a;
		game->a = elem->next;
		elem->next = NULL;
		ft_lstadd_front(&(game->b), elem);
		game->len_a = game->len_a - 1;
		game->len_b = game->len_b + 1;
		return (add_history(game, "pb"));
	}
	return (1);
}

/**
 * Push all the elements of b on a
 * @return 1 if success, 0 else
*/
int	push_b_on_a(t_game *game)
{
	t_list	*lst;

	if (game->len_b > 0)
	{
		lst = create_offset_list(game->len_b);
		if (!lst)
			return (0);
		while (game->len_b)
		{
			if (!push_a(game))
				return (0);
		}
		ft_lstadd_front(&(game->offset_a), lst);
		ft_lstclear(&(game->offset_b), &free);
	}
	return (1);
}
