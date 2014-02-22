#include "includes/lemmin.h"

t_room	*new_room(char *name, int x, int y, t_rtype type)
{
	t_room	*r;

	r = (t_room*)malloc(sizeof(t_room));
	r->name = name;
	r->x = x;
	r->y = y;
	r->dist = -1;
	r->type = type;
	r->busy = 0;
	r->pipes = NULL;
	r->next = NULL;
	return (r);
}

void	add_room(char *name, int x, int y, t_rtype type)
{
	t_anthill	*anthill;
	t_room	*new;
	t_room	*tmp;

	anthill = get_anthill();
	new = new_room(name, x, y, type);
	tmp = anthill->rooms;
	if (tmp == NULL)
		anthill->rooms = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (type == START)
		anthill->start = new;
	if (type == END)
		anthill->end = new;
}

t_room	*find_room(char *name)
{
	t_room	*tmp;

	tmp = get_anthill()->rooms;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
