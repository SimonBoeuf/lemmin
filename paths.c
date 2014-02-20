#include "includes/lemmin.h"

t_paths	*new_paths(t_path *path)
{
	t_paths	*p;

	p = (t_paths*)malloc(sizeof(t_paths));
	p->path = path;
	p->next = NULL;
	p->length = 0;
	return (p);
}

void	add_paths(t_path *p)
{
	t_anthill	*anthill;
	t_paths		*new;
	t_paths		*tmp;

	anthill = get_anthill();
	new = new_paths(p);
	tmp = anthill->paths;
	if (tmp == NULL)
		anthill->paths = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		enough_paths(void)
{
	t_paths	*paths;
	int		nb_paths;
	int		min_move;
	int		shortest_path;

	paths = get_anthill()->paths;
	if (paths == NULL)
		return (0);
	while (paths != NULL)
	{
		nb_paths++;
		min_move = shortest_path + get_anthill()->ants - nb_paths;
		if (nb_paths == get_anthill()->ants || min_move > )
			return (1);
		paths = paths->next;
	}

}
