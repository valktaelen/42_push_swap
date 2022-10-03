/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:30:13 by aartiges          #+#    #+#             */
/*   Updated: 2022/10/04 01:09:43 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Create a new element for the list 
 */
t_stack	*new_content(char *nb)
{
	t_stack	*ret;

	if (!nb)
		return (NULL);
	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->nb = ft_atoi_custom_long(nb);
	return (ret);
}

/**
 * Create a list with the params of the program
 */
t_list	*create_list(char **params, int len)
{
	t_list	*stack_a;
	t_list	*tmp;
	t_stack	*content;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < len && params[i])
	{
		content = new_content(params[i]);
		if (!content)
			return ((t_list *)free_list_null(&stack_a, &free_stack));
		tmp = ft_lstnew((void *)content);
		if (!tmp)
		{
			free(content);
			return ((t_list *)free_list_null(&stack_a, &free_stack));
		}
		ft_lstadd_back(&stack_a, tmp);
		++i;
	}
	return (stack_a);
}

/**
 * Create a new element offset (int *)
 * @param int offset The value of the offset
 * @return The pointer on the offset or NULL if error
*/
int	*create_offset(int offset)
{
	int	*off;

	off = malloc(sizeof(int));
	if (!off)
		return (NULL);
	*off = offset;
	return (off);
}

/**
 * Create a new element of the list of offsets
 * @param int offset The value of the offset
 * @return The pointer on the offset or NULL if error
*/
t_list	*create_offset_list(int offset)
{
	int		*val;
	t_list	*lst;

	val = create_offset(offset);
	if (!val)
		return (NULL);
	lst = ft_lstnew(val);
	if (!lst)
	{
		free(val);
		return (NULL);
	}
	return (lst);
}

char	*str_join_free_s1(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin_null(s1, " ");
	if (s1)
		free(s1);
	if (!tmp)
		return (NULL);
	ret = ft_strjoin_null(tmp, s2);
	free(tmp);
	if (!ret)
		return (NULL);
	return (ret);
}
