/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:38:50 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/08 16:52:15 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Apply the quick sort on the stack corresponding to list
 * @param t_game *game The game
 * @param int list The identifier of the list (show define
 * in push_swap.h -- LST_A or LST_B)
 * @param int direction The operation
 * @param int (*push)(t_game *game) A pointer on the function use to push
 * @param int *offset A pointer on the size of the partition
 * @return 1 if success, 0 else
*/
int	sort(t_game *game, int list, int direction, int (*push)(t_game *game),
	int *offset)
{
	if (list != LST_A && list != LST_B)
		return (0);
	if (direction == SWAP)
	{
		if (!swap(game) && !(*push)(game))
			return (0);
	}
	else if (direction == PUSH)
	{
		if (!(*push)(game) || !change_offset(game, list, -1))
			return (0);
		*offset = *offset + 1;
		return (swap(game));
	}
	else
	{
		if (direction == BEGIN && !rotate(game, list))
			return (0);
		else if (direction == END && !rev_rotate(game, list))
			return (0);
		return (swap(game));
	}
	return (1);
}

/**
 * Sort the game
 * @param t_game *game
 * @return 1 if success, 0 else
*/
int	sort_game(t_game *game)
{
	while (game && !check_finish(game))
	{
		while (check_increasing_stack(game->a, game->len_a) == 0)
		{
			if (!sort_curent_partition_a(game))
				return (0);
		}
		if (check_decreasing_stack(game->b, game->len_b) == 1)
			push_b_on_a(game);
		while (check_decreasing_stack(game->b, game->len_b) == 0
			&& check_increasing_stack(game->a, game->len_a) == 1)
		{
			if (!sort_curent_partition_b(game))
				return (0);
		}
	}
	return (1);
}
