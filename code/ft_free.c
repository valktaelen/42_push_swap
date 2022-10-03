/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:33:24 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/09 20:06:56 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Free a t_stack* but the param is a void * (for the t_list::content)
 */
void	free_stack(void *stack)
{
	t_stack	*val;

	val = stack;
	val->nb = 0;
	free(val);
}

/**
 * Free the struct game and all the contents
 */
void	free_game(t_game **game)
{
	if (game)
	{
		ft_lstclear(&((*game)->a), &free_stack);
		ft_lstclear(&((*game)->b), &free_stack);
		ft_lstclear(&((*game)->steps), &free);
		ft_lstclear(&((*game)->offset_a), &free);
		ft_lstclear(&((*game)->offset_b), &free);
		free(*game);
		*game = NULL;
	}
}

/**
 * Free a t_list and all the contents, return NULL
 */
void	*free_list_null(t_list **list, void (*del)(void *))
{
	ft_lstclear(list, del);
	return (NULL);
}

/**
 * Free one element of a list and return the next element of the
 * element that is free
 * @param t_list *lst The element that will be free
 * @return The next element of the list (after the element free)
 */
t_list	*free_one_get_next(t_list *lst)
{
	t_list	*ret;

	ret = lst->next;
	ft_lstdelone(lst, &free);
	return (ret);
}

/**
 * Free the first element of the list of offsets done in param
 * @param t_list **lst A pointer on the list of offsets
*/
void	free_offset_head(t_list **lst)
{
	t_list	*list;

	if (lst && *lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, &free);
		*lst = list;
	}
}
