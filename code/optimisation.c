/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:16:38 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/09 20:29:48 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Get the max of the stack lst after cur_max
 * @param t_list *lst The stack
 * @param int cur_max The curent max
 * @return The max of the stack, inferior of cur_max
 * If no match return INT_MIN (/!\ match is INT_MIN if INT_MIN is in the stack
 * and cur_max is superiror at INT_MIN and inferior at the 2nd element of stack
 * when increasing)
*/
int	max_stack(t_list *lst, int cur_max)
{
	t_stack	*tmp;
	int		max;

	if (!lst)
		return (cur_max);
	max = INT_MIN;
	while (lst)
	{
		tmp = lst->content;
		if (tmp->nb > max && tmp->nb < cur_max)
			max = tmp->nb;
		lst = lst->next;
	}
	if (max == INT_MIN && max < cur_max)
		return (cur_max);
	return (max);
}

/**
 * Get the min of the stack lst after cur_min
 * @param t_list *lst The stack
 * @param int cur_min The curent min
 * @return The min of the stack, inferior of cur_min
 * If no match return INT_MAX (/!\ match is INT_MAX if INT_MAX is in the stack
 * and cur_max is inferior at INT_MAX and superior at the 2nd element of stack
 * when decreasing)
*/
int	min_stack(t_list *lst, int cur_min)
{
	t_stack	*tmp;
	int		min;

	if (!lst)
		return (cur_min);
	min = INT_MAX;
	while (lst)
	{
		tmp = lst->content;
		if (tmp->nb < min && tmp->nb > cur_min)
			min = tmp->nb;
		lst = lst->next;
	}
	if (min == INT_MAX && min > cur_min)
		return (cur_min);
	return (min);
}

/**
 * Find the pivot point of the partition
 * @param t_list *list The stack
 * @param int offset The size of the partition
 * @param int (*ext_stack)(t_list *lst, int curent)) The function min_stack
 * or max_stack
 * @return The value of the pivot point of the partition
*/
int	find_mid(t_list *list, int offset, int (*ext_stack)(t_list *lst,
	int curent))
{
	int		mid[2];
	int		cmp;
	t_list	*lst_offset[2];

	cmp = (offset - 2) / 2 + 1;
	lst_offset[0] = list;
	while (offset > 1 && lst_offset[0] && lst_offset[0]->next)
	{
		--offset;
		lst_offset[0] = lst_offset[0]->next;
	}
	lst_offset[1] = lst_offset[0]->next;
	lst_offset[0]->next = NULL;
	mid[0] = (*ext_stack)(list, INT_MIN);
	if (ext_stack == &max_stack)
		mid[0] = (*ext_stack)(list, INT_MAX);
	mid[1] = (*ext_stack)(list, mid[0]);
	while (cmp > 0 && mid[0] != mid[1])
	{
		--cmp;
		mid[0] = mid[1];
		mid[1] = (*ext_stack)(list, mid[0]);
	}
	lst_offset[0]->next = lst_offset[1];
	return (mid[0]);
}
