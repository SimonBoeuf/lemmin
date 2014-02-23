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
	if (p->next != NULL && p->next->room->type != END)
		move_ant(p->next);
	p->next->ant = p->ant;
	p->ant = NULL;
}

void	move_ants(t_paths *p)
{
	t_path	*path;

	path = p->path;
	if (path != NULL)
		move_ant(path);
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

	ants_left = get_ants_left();
	if (ants_left == 0)
		return (NULL);
	ft_putnbr(ants_left);
	i = get_anthill()->ants - ants_left;
	tmp = get_anthill()->ant;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	ft_putendl(tmp->name);
	return (tmp);
}
