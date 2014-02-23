/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:43:38 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:53:11 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

t_path	*new_path(t_room *r, int dist)
{
	t_path	*p;

	p = (t_path*)malloc(sizeof(t_path));
	p->room = r;
	p->room->dist = dist;
	p->ant = NULL;
	p->next = NULL;
	return (p);
}

void	add_path(t_path **start, t_room *r, int dist)
{
	t_path		*new;

	new = new_path(r, dist);
	if (*start == NULL)
	{
		*start = new;
	}
	else
	{
		new->next = (*start);
		*start = new;
	}
}

void	reset_dists(t_path *p)
{
	t_room	*tmp;

	tmp = get_anthill()->rooms;
	while (tmp != NULL)
	{
		if (tmp->dist > -1)
			tmp->dist = -1;
		tmp = tmp->next;
	}
	while (p != NULL)
	{
		p->room->dist = -2;
		p = p->next;
	}
}

void	dijkstra(void)
{
	t_path	*p;

	get_anthill()->start->dist = 0;
	get_anthill()->end->dist = -1;
	affect_dist(get_anthill()->start, 0);
	p = get_path();
	add_paths(p);
	reset_dists(p);
}

void	affect_dist(t_room *r, int dist)
{
	t_pipe	*pipes;

	dist++;
	pipes = get_anthill()->pipes;
	while (pipes != NULL)
	{
		if (pipes->r1 == r && (pipes->r2->dist > dist || pipes->r2->dist == -1))
		{
			pipes->r2->dist = dist;
			if (pipes->r2->type != END)
				affect_dist(pipes->r2, dist);
		}
		if (pipes->r2 == r && (pipes->r1->dist > dist || pipes->r1->dist == -1))
		{
			pipes->r1->dist = dist;
			if (pipes->r1->type != END)
				affect_dist(pipes->r1, dist);
		}
		pipes = pipes->next;
	}
}
