/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:37:40 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/08 16:35:34 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Step 1 of sort on b.
 * If the stack b is not sort but the partition on the top of the heap b
 * is sort, all the partition is push on a
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_b_step_1(t_game *game, int *offset)
{
	int	new_offset;

	new_offset = 0;
	while (*offset > 0 && check_decreasing_stack(game->b, *offset) == 1)
	{
		push_a(game);
		*offset = *offset - 1;
		++new_offset;
	}
	return (create_new_offset(&(game->offset_a), new_offset));
}

/**
 * Step 2 of sort on b.
 * If the partition on the top of b is not sort, the quick sort is apply
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_b_step_2(t_game *game, int *offset)
{
	int	new_offset;
	int	mid;
	int	exe;
	int	extrem;

	new_offset = 0;
	mid = find_mid(game->b, *offset, &max_stack);
	exe = short_way_op(game->b, SUP, mid);
	extrem = 0;
	while (exe != NOTHING && *offset)
	{
		if (exe == BEGIN)
			++extrem;
		if (!sort(game, LST_B, exe, &push_a, &new_offset))
			return (0);
		exe = short_way_op(game->b, SUP, mid);
	}
	while (game->offset_b->next && extrem > 0)
	{
		--extrem;
		rev_rotate(game, LST_B);
	}
	return (create_new_offset(&(game->offset_a), new_offset));
}

/**
 * Step of the sort the partion on the top of the stack b
 * @param t_game *game The game
 * @param int *offset A pointer on the offset (size of the partition)
 * @return 1 if success, 0 else
*/
static int	sort_b(t_game *game, int *offset)
{
	if (!sort_b_step_1(game, offset))
		return (0);
	if (*offset > 0 && !sort_b_step_2(game, offset))
		return (0);
	if (*offset > 0 && !sort_b_step_1(game, offset))
		return (0);
	return (1);
}

/**
 * Sort the partion on the top of the stack b
 * @param t_game *game The game
 * @return 1 if success, 0 else
*/
int	sort_curent_partition_b(t_game *game)
{
	int	*offset;

	offset = get_curent_offset(game->offset_b);
	if (!offset)
		return (0);
	if (!sort_inf_4(game))
		return (0);
	if (!sort_b(game, offset))
		return (0);
	if (*offset == 0)
		free_offset_head(&(game->offset_b));
	return (1);
}
