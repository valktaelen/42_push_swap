/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:33:24 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/13 23:25:59 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			++i;
		}
		free(split);
	}
}

void	free_args(char ***args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		free_split(args[i]);
		++i;
	}
	if (args)
		free(args);
}
