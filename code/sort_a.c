/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:20:44 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/09 20:23:24 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Step 1 of sort on a.
 * If the stack a is not sort but the partition on the top of the heap a
 * is sort, all the partition is push on b
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_a_step_1(t_game *game, int *offset)
{
	int	new_offset;

	new_offset = 0;
	while (*offset > 0 && game->len_a != *offset
		&& check_increasing_stack(game->a, game->len_a) == 0
		&& check_increasing_stack(game->a, *offset) == 1)
	{
		push_b(game);
		*offset = *offset - 1;
		++new_offset;
	}
	return (create_new_offset(&(game->offset_b), new_offset));
}

/**
 * Step 2 of sort on a.
 * If the partition on the top of a is not sort, the quick sort is apply
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_a_step_2(t_game *game, int *offset)
{
	int	mid;
	int	new_offset;
	int	exe;
	int	extrem;

	new_offset = 0;
	mid = find_mid(game->a, *offset, &min_stack);
	exe = short_way_op(game->a, INF, mid);
	extrem = 0;
	while (exe != NOTHING && *offset > 2)
	{
		if (exe == BEGIN)
			++extrem;
		if (!sort(game, LST_A, exe, &push_b, &new_offset))
			return (0);
		exe = short_way_op(game->a, INF, mid);
	}
	if (!clear_reverse(game, LST_A, extrem))
		return (0);
	if (!create_new_offset(&(game->offset_b), new_offset))
		return (0);
	if (*offset <= 3 && !sort_inf_4(game))
		return (0);
	return (1);
}

/**
 * Step of the sort the partion on the top of the stack a
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_a(t_game *game, int *offset)
{
	if (!sort_a_step_1(game, offset))
		return (0);
	if (*offset > 0 && !sort_a_step_2(game, offset))
		return (0);
	if (*offset > 0 && !sort_a_step_1(game, offset))
		return (0);
	return (1);
}

/**
 * Sort the partion on the top of the stack a
 * @param t_game *game The game
 * @return 1 if success, 0 else
*/
int	sort_curent_partition_a(t_game *game)
{
	int	*offset;

	offset = get_curent_offset(game->offset_a);
	if (!offset)
		return (0);
	if (*offset <= 3 && !sort_inf_4(game))
		return (0);
	if (!sort_a(game, offset))
		return (0);
	if (*offset == 0)
		free_offset_head(&(game->offset_a));
	return (1);
}
