/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:42:31 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:56:51 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

t_anthill		*init_anthill(void)
{
	t_anthill	*anthill;

	anthill = (t_anthill*)malloc(sizeof(t_anthill));
	anthill->ants = 0;
	anthill->ants_left = 0;
	anthill->start = NULL;
	anthill->end = NULL;
	anthill->rooms = NULL;
	anthill->paths = NULL;
	anthill->ant = NULL;
	return (anthill);
}

t_anthill		*get_anthill(void)
{
	static t_anthill	*anthill = NULL;

	if (anthill == NULL)
		anthill = init_anthill();
	return (anthill);
}

int				finished(void)
{
	t_paths	*paths;
	t_path	*path;

	paths = get_anthill()->paths;
	while (paths != NULL)
	{
		path = paths->path;
		while (path != NULL)
		{
			if (path->ant != NULL)
				return (0);
			path = path->next;
		}
		paths = paths->next;
	}
	return (1);
}

void			move_ants(t_paths *p)
{
	t_path	*path;

	path = p->path;
	if (path != NULL)
		move_ant(path);
}

