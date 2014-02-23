/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:43:00 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:57:59 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

void	lemmin(void)
{
	get_map();
	add_ants();
	find_paths();
	if (get_anthill()->paths == NULL || get_anthill()->paths->path == NULL)
	{
		ft_putendl("No solutions");
		exit (0);
	}
	resolve();
}

void	get_map(void)
{
	int		r;
	char	*line;
	int		map;

	map = 1;
	while ((r = get_next_line(0, &line)) > 0 && map)
		if (!(map = handle_line(line)))
			break ;
	if (r == -1)
		strerror(errno);
}

void	find_paths(void)
{
	while (!enough_paths())
		dijkstra();
}

void	resolve(void)
{
	t_paths	*paths;
	int		i;
	int		path_number;

	paths = get_anthill()->paths;
	path_number = get_paths_number();
	i = 0;
	while (i < path_number)
	{
		move_ants(paths);
		if ((i == 0 || get_anthill()->ants_left > paths->length -
					get_anthill()->paths->length) && paths->path != NULL)
		{
			paths->path->ant = get_next_ant();
			if (get_next_ant() != NULL)
				get_anthill()->ants_left--;
		}
		i++;
		paths = paths->next;
	}
	if (!finished())
	{
		ft_putendl("");
		resolve();
	}
}
