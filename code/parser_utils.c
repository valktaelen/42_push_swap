/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 08:24:43 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/13 23:46:12 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Check if the list have double number
 * @param t_game *game The game
*/
int	has_double(t_game *game)
{
	t_list	*lst;
	t_list	*tmp;
	t_stack	*elem;
	t_stack	*elem_tmp;

	if (game)
	{
		lst = game->a;
		while (lst)
		{
			elem = lst->content;
			tmp = lst->next;
			while (tmp)
			{
				elem_tmp = tmp->content;
				if (elem_tmp->nb == elem->nb)
					return (1);
				tmp = tmp->next;
			}
			lst = lst->next;
		}
	}
	return (0);
}

char	*unsplit_args(char **argv, int argc)
{
	char	***args;
	int		i[2];
	char	*ret;

	args = split_args(argv, argc);
	if (!args)
		return (NULL);
	i[0] = 0;
	ret = NULL;
	while (args[i[0]])
	{
		i[1] = 0;
		while (args[i[0]][i[1]])
		{
			ret = str_join_free_s1(ret, args[i[0]][i[1]]);
			if (!ret)
				return (NULL);
			++i[1];
		}
		++i[0];
	}
	free_args(args);
	return (ret);
}

char	***split_args(char **params, int len)
{
	int		i;
	char	***ret;

	ret = malloc(len * sizeof(char **));
	if (!ret)
		return (NULL);
	i = 1;
	ret[len - 1] = NULL;
	while (i < len && params[i])
	{
		ret[i - 1] = ft_split(params[i], ' ');
		if (!params[i - 1])
		{
			i = i - 2;
			while (i - 2 >= 0)
				free_split(ret[i--]);
			free(ret);
			return (NULL);
		}
		++i;
	}
	return (ret);
}
