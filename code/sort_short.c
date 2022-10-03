/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:11:32 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/08 16:55:27 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sort the stack a if the len of partition on the top of a is inferior to 4
 * @param t_game *game The game
 * @return 1 if success, 0 else
*/
static int	sort_inf_4_a(t_game *game)
{
	int	*val;

	val = get_curent_offset(game->offset_a);
	if (!val)
		return (1);
	if (*val <= 3)
	{
		if (!swap(game))
			return (0);
		if (*val == 3 && check_increasing_stack(game->a, *val) == 0)
		{
			if (game->len_a == *val)
			{
				if (!rev_rotate(game, LST_A))
					return (0);
			}
			else if (!push_b(game) || !swap(game) || !push_a(game))
				return (0);
			if (!swap(game))
				return (0);
		}
	}
	return (1);
}

/**
 * Sort the stack b if the len of partition on the top of a is inferior to 4
 * @param t_game *game The game
 * @return 1 if success, 0 else
*/
static int	sort_inf_4_b(t_game *game)
{
	int	*val;

	val = get_curent_offset(game->offset_b);
	if (!val)
		return (1);
	if (*val <= 3)
	{
		if (!swap(game))
			return (0);
		if (*val == 3 && check_decreasing_stack(game->b, *val) == 0)
		{
			if (game->len_b == *val)
			{
				if (!rev_rotate(game, LST_B))
					return (0);
			}
			else if (!push_a(game) || !swap(game) || !push_b(game))
				return (0);
			if (!swap(game))
				return (0);
		}
	}
	return (1);
}

/**
 * Sort the stack a and b
 * if the len of partition on the top of a is inferior to 4
 * @param t_game *game The game
 * @return 1 if success, 0 else
*/
int	sort_inf_4(t_game *game)
{
	return (sort_inf_4_a(game) && sort_inf_4_b(game));
}
