/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:07:10 by aartiges          #+#    #+#             */
/*   Updated: 2022/10/04 01:09:46 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Test if a string is a number and only a number
 * @param char *txt The string to test
 * @return 1 if the string is a number, 0 else
 */
static int	is_number(char *txt)
{
	if (!txt)
		return (0);
	while (ft_isspace(*txt))
		++txt;
	if (*txt == '-' || *txt == '+')
		++txt;
	while (*txt)
	{
		if (!ft_isdigit((int)*txt))
			return (0);
		++txt;
	}
	return (1);
}

/**
 * Initialise the game struct with a and len_a
 * @param t_game *game The game
 * @param t_list *a The list of elements t_stack
 * @param int len_a The size of the list a
 */
static int	init_game(t_game *game, t_list	*a, int len_a)
{
	t_list	*offset;

	offset = create_offset_list(len_a);
	if (!offset)
		return (0);
	game->offset_a = offset;
	game->a = a;
	game->b = NULL;
	game->len_a = len_a;
	game->len_b = 0;
	game->steps = NULL;
	game->offset_b = NULL;
	game->min = min_stack(a, INT_MIN);
	game->max = max_stack(a, INT_MAX);
	return (1);
}

/**
 * Test if the entry of the program is good
 * (all of the arguments are number and in the range of the integers)
 */
static int	check_entry(char **params, int len)
{
	char	*tmp;
	long	test;
	size_t	len_max;
	int		i;

	tmp = ft_itoa(INT_MIN);
	if (!tmp)
		return (0);
	len_max = ft_strlen(tmp);
	free(tmp);
	i = 0;
	while (i < len)
	{
		if (ft_strlen(params[i]) > len_max || !is_number(params[i]))
			return (0);
		test = ft_atoi_custom_long(params[i]);
		if (test > INT_MAX || test < INT_MIN)
			return (0);
		++i;
	}
	return (1);
}

/**
 * Parse the entry of the program
 */
static t_game	*parser_entry(char **params, int len)
{
	t_list	*stack_a;
	t_game	*game;

	stack_a = create_list(params, len);
	if (!stack_a)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (init_game(game, stack_a, len))
		return (game);
	return (NULL);
}

/**
 * Parse the arguments and return the game (list a)
 * @param char **params all the params of the program
 * @param int len number of params received by the program
 * @return The initial game with a and len_a initialise. b = NULL and len_b = 0.
 * If an error occurs NULL is return (and the work did are free)
 */
t_game	*parser(char **params, int len)
{
	t_game	*game;

	if (check_entry(params, len))
	{
		game = parser_entry(params, len);
		if (has_double(game))
		{
			free_game(&game);
			return (NULL);
		}
		return (game);
	}
	return (NULL);
}
