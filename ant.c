/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:42:27 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:54:18 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

t_ant	*new_ant(char *name)
{
	t_ant	*a;

	a = (t_ant*)malloc(sizeof(t_ant));
	a->name = name;
	a->next = NULL;
	a->busy = 0;
	return (a);
}

void	add_ant(char *name)
{
	t_ant	*tmp;
	t_ant	*new;

	tmp = get_anthill()->ant;
	new = new_ant(name);
	if (tmp == NULL)
		get_anthill()->ant = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	move_ant(t_path *p)
{
	if (p->next != NULL)
	{
		if (p->ant != NULL)
		{
			ft_putstr(p->ant->name);
			ft_putstr("->");
			ft_putstr(p->next->room->name);
			ft_putstr(" ");
		}
		if (p->next->room->type != END)
			move_ant(p->next);
	}
	p->next->ant = p->ant;
	p->ant = NULL;
}

int		get_ants_left(void)
{
	int		i;
	t_paths	*ps;
	t_path	*p;

	i = get_anthill()->ants;
	ps = get_anthill()->paths;
	while (ps != NULL)
	{
		p = ps->path;
		while (p != NULL)
		{
			if (p->ant != NULL)
				i--;
			p = p->next;
		}
		ps = ps->next;
	}
	return (i);
}

t_ant	*get_next_ant(void)
{
	int		i;
	int		ants_left;
	t_ant	*tmp;

	ants_left = get_anthill()->ants_left;
	if (ants_left == 0)
		return (NULL);
	i = get_anthill()->ants - ants_left;
	tmp = get_anthill()->ant;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}
