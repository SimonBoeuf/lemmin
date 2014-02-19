#include "includes/lemmin.h"

t_room	*new_room(char *name, int x, int y, t_rtype type)
{
	t_room	*r;

	r = (t_room*)malloc(sizeof(t_room));
	r->name = name;
	r->x = x;
	r->y = y;
	r->type = type;
	r->dist = -1;
	r->pipes = NULL;
	r->next = NULL;
	return (r);
}

void	add_room(char *name, int x, int y, t_rtype type)
{
	t_rooms	*rooms;
	t_room	*new;
	t_room	*tmp;

	rooms = get_rooms();
	new = new_room(name, x, y, type);
	tmp = rooms->rooms;
	if (tmp == NULL)
		rooms->rooms = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (type == START)
		rooms->start = new;
	if (type == END)
		rooms->end = new;
}

t_room	*find_room(char *name)
{
	t_room	*tmp;

	tmp = get_rooms()->rooms;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
