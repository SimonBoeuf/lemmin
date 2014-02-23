/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:53:15 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:53:26 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

t_path	*get_path(void)
{
	t_room	*r;
	t_path	*p;
	t_pipe	*pipes;

	r = get_anthill()->end;
	p = NULL;
	add_path(&p, r, r->dist);
	while (r->dist > 0)
	{
		pipes = get_anthill()->pipes;
		while (pipes != NULL)
		{
			if ((pipes->r1 == r && pipes->r2->dist == r->dist -1)
					|| (pipes->r2 == r && pipes->r1->dist == r->dist -1))
			{
				r = pipes->r1 == r ? pipes->r2 : pipes->r1;
				add_path(&p, r, r->dist);
			}
			pipes = pipes->next;
		}
	}
	return (p->room->type == START ? p : NULL);
}
