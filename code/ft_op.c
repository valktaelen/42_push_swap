/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:27:51 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/01 04:48:21 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Create the manipulation in the history
 * @param char const *history the notation of the maninipulation to add
 * in the history
 * @return The new manipulation history (1 element of type t_list) or NULL
 * if an allocation issue occurs
 */
t_list	*get_new_hist(const char *history)
{
	char	*tmp;
	t_list	*elem;

	tmp = ft_strdup(history);
	if (!tmp)
		return (NULL);
	elem = ft_lstnew(tmp);
	if (!elem)
	{
		free(tmp);
		return (NULL);
	}
	return (elem);
}

/**
 * Add the manipulation in the history
 * @param t_game game pointer on the game (place where the history is)
 * @param char const *history the notation of the maninipulation to add
 * in the history
 * @return 0 if there is an error, 1 else
 */
int	add_history(t_game *game, const char *history)
{
	t_list	*elem;

	elem = get_new_hist(history);
	if (!elem)
		return (0);
	ft_lstadd_back(&(game->steps), elem);
	return (1);
}

/**
 * Print all the history of the manipulations
 */
void	ft_print_op(t_game *game)
{
	char	*tmp;
	t_list	*lst;

	lst = game->steps;
	while (lst)
	{
		tmp = (char *)lst->content;
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
		lst = lst->next;
	}
}

/**
 * Remove the elements cur and cur->next from the t_list lst
 * @param t_list **lst pointer to the first element of the list
 * @param t_list *cur curent element of the list that we want to remove
 * the next will also be remove
 * @param t_list *prec the element of the list before the cur element, if
 * NULL cur is at start of the list
 * @return The new current element of the list
 */
t_list	*remove_2_curents(t_list **lst, t_list *cur, t_list *prec)
{
	cur = free_one_get_next(cur);
	cur = free_one_get_next(cur);
	if (prec)
		prec->next = cur;
	else
		*lst = cur;
	return (cur);
}

/**
 * Remove the elements cur and cur->next from the t_list lst and change
 * these elements by a new element with the good history manipulation
 * @param t_list **l pointer to the first element of the list
 * @param t_list *cur curent element of the list that we want to remove
 * the next will also be remove
 * @param t_list *prec the element of the list before the cur element, if
 * NULL cur is at start of the list
 * @param char const *n the notation of the maninipulation to add
 * in the history
 * @return The new current element of the list
 */
t_list	*change_2_curents(t_list **l, t_list *cur, t_list *pre, const char *n)
{
	t_list	*tmp;

	tmp = get_new_hist(n);
	if (tmp)
	{
		cur = remove_2_curents(l, cur, pre);
		if (pre)
			pre->next = tmp;
		else
			*l = tmp;
		tmp->next = cur;
		return (tmp);
	}
	return (cur);
}
