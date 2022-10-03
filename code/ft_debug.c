/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:43:38 by aartiges          #+#    #+#             */
/*   Updated: 2021/12/09 20:07:36 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

/**
 * Print the game
*/
void	ft_debug_game(t_game *game)
{
	t_list	*tmp;
	t_stack	*val;
	int		*ent;

	printf("Game = %p\n\n", game);
	if (game)
	{
		tmp = game->a;
		printf("a) %p len : %d\n", tmp, game->len_a);
		while (tmp)
		{
			val = (t_stack *)tmp->content;
			printf("\tint = %d\n", val->nb);
			tmp = tmp->next;
		}
		tmp = game->b;
		printf("b) %p len : %d\n", tmp, game->len_b);
		while (tmp)
		{
			val = (t_stack *)tmp->content;
			printf("\tint = %d\n", val->nb);
			tmp = tmp->next;
		}
		tmp = game->offset_a;
		printf("a) %p len : %d\n", tmp, ft_lstsize(tmp));
		while (tmp)
		{
			ent = (int *)tmp->content;
			printf("\tint = %d\n", *ent);
			tmp = tmp->next;
		}
		tmp = game->offset_b;
		printf("b) %p len : %d\n", tmp, ft_lstsize(tmp));
		while (tmp)
		{
			ent = (int *)tmp->content;
			printf("\tint = %d\n", *ent);
			tmp = tmp->next;
		}
		printf("Max : %d\n", game->max);
		printf("Min : %d\n", game->min);
	}
	printf("\n\n#####\n");
}
