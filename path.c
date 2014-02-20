#include "includes/lemmin.h"

t_path	*new_path(t_room *r, int dist)
{
	t_path	*p;

	p = (t_path*)malloc(sizeof(t_path));
	p->room = r;
	p->dist = dist;
	p->next = NULL;
	return (p);
}

void	add_path(t_room *r, int dist)
{
	t_anthill	*anthill;
	t_path		*new;
	t_path		*tmp;

	anthill = get_anthill();
	new = new_path(r, dist);
	if (anthill->paths == NULL)
		anthill->paths = new_paths(new);
	else
	{
		tmp = anthill->paths->path;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	dijkstra(void)
{

}
