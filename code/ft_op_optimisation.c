/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_optimisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:27:51 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/05 08:48:24 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_scotch(t_list ***hist, t_list **cur, t_list **prec)
{
	if (check_ops((*cur)->content, "ra", (*cur)->next->content, "rb")
		|| check_ops((*cur)->content, "rb", (*cur)->next->content, "ra"))
	{
		*prec = change_2_curents((*hist), (*cur), *prec, "rr");
		(*cur) = (*prec)->next;
	}
	else if (check_ops((*cur)->content, "rra", (*cur)->next->content, "rrb")
		|| check_ops((*cur)->content, "rrb", (*cur)->next->content, "rra"))
	{
		(*prec) = change_2_curents((*hist), (*cur), (*prec), "rrr");
		(*cur) = (*prec)->next;
	}
	else
	{
		(*prec) = (*cur);
		(*cur) = (*cur)->next;
	}
}

/**
 * Take the list of steps and simplify the history's steps
 * @param t_list **hist Pointer on the list of steps
 */
void	ft_simplify_ops(t_list **hist)
{
	t_list	*cur;
	t_list	*prec;

	if (!*hist)
		cur = NULL;
	cur = *hist;
	prec = NULL;
	while (cur && cur->next)
	{
		if (check_ops(cur->content, "sa", cur->next->content, "sa")
			|| check_ops(cur->content, "sb", cur->next->content, "sb")
			|| check_ops(cur->content, "pa", cur->next->content, "pb")
			|| check_ops(cur->content, "pb", cur->next->content, "pa"))
			cur = remove_2_curents(hist, cur, prec);
		else if (check_ops(cur->content, "sa", cur->next->content, "sb")
			|| check_ops(cur->content, "sb", cur->next->content, "sa"))
		{
			prec = change_2_curents(hist, cur, prec, "ss");
			cur = prec->next;
		}
		else
			op_scotch(&hist, &cur, &prec);
	}
}
