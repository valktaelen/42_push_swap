/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:54:58 by aartiges          #+#    #+#             */
/*   Updated: 2022/10/04 01:11:28 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Show the message or "Error\n" if message is null.
 * And exit the program.
 * @param char *message message to write on the std-error
 */
void	fatal_error(char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	else
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	size_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			++i;
	}
	return (i);
}

t_game	*parse_all_entry(int argc, const char *argv[])
{
	char	*new_entry;
	char	**full_split;
	t_game	*game;

	new_entry = unsplit_args((char **)argv, argc);
	if (!new_entry)
		return (NULL);
	full_split = ft_split(new_entry, ' ');
	free(new_entry);
	if (!full_split)
		return (NULL);
	game = parser(full_split, size_split(full_split));
	free_split(full_split);
	return (game);
}

int	main(int argc, const char *argv[])
{
	t_game	*game;
	int		tmp;

	if (argc == 1)
		return (0);
	game = parse_all_entry(argc, argv);
	if (!game)
		fatal_error(NULL);
	if (!sort_game(game))
	{
		free_game(&game);
		fatal_error(NULL);
	}
	tmp = ft_lstsize(game->steps);
	ft_simplify_ops(&(game->steps));
	while (tmp != ft_lstsize(game->steps))
	{
		tmp = ft_lstsize(game->steps);
		ft_simplify_ops(&(game->steps));
	}
	ft_print_op(game);
	free_game(&game);
	return (0);
}
