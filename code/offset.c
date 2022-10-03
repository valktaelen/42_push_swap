/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:26:56 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/08 14:13:58 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Get the first offset of the list of offset done in param
 * @param t_list *offset list of offsets
 * @return The pointer on the offset or NULL
 */
int	*get_curent_offset(t_list *offset)
{
	int	*val;

	if (!offset)
		return (NULL);
	val = offset->content;
	return (val);
}

/**
 * Change the value of the offset that correspond to the list
 * list_that_modify (LST_A or LST_B)
 * @param t_game *game The game
 * @param int list_that_modify The identifier of the list (show define
 * in push_swap.h -- LST_A or LST_B)
 * @param int change The value to add at the offset
 * @param return 1 if success, 0 else
*/
int	change_offset(t_game *game, int list_that_modify, int change)
{
	int	*val;

	val = NULL;
	if (list_that_modify == LST_B)
		val = get_curent_offset(game->offset_b);
	else
		val = get_curent_offset(game->offset_a);
	if (!val)
		return (0);
	*val = *val + change;
	return (1);
}

/**
 * Add a new offset new_offset at the list offset
 * @param t_list **offset A pointer on the list of offset
 * @param int new_offset The value of the new offset
 * @return 1 if success, 0 else
*/
int	create_new_offset(t_list **offset, int new_offset)
{
	t_list	*elem;

	if (new_offset > 0)
	{
		elem = create_offset_list(new_offset);
		if (!elem)
			return (0);
		ft_lstadd_front(offset, elem);
	}
	return (1);
}

/**
 * rev_rotate all the elements that have rotate
 * @param t_game The game
 * @param int list_that_modify The identifier of the list (show define
 * in push_swap.h -- LST_A or LST_B)
 * @param int extrem the number of rotate that is apply
 * @return 1 if succes, 0 else
*/
int	clear_reverse(t_game *game, int list, int extrem)
{
	t_list	*lst;

	if (list == LST_A)
		lst = game->offset_a->next;
	else if (list == LST_B)
		lst = game->offset_b->next;
	else
		return (0);
	while (lst && extrem > 0)
	{
		--extrem;
		if (!rev_rotate(game, list))
			return (0);
	}
	return (1);
}
