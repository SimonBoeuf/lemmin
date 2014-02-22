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

	paths = get_anthill()->paths;
	if (paths == NULL)
		return (0);
	nb_paths = 0;
	while (paths != NULL)
	{
		nb_paths++;
		paths = paths->next;
	}
	if (nb_paths == get_anthill()->ants || no_paths_left())
		return (1);
	return (0);
}

int		no_paths_left(void)
{
	t_pipe	*pipes;

	pipes = get_anthill()->pipes;
	while (pipes != NULL)
	{
		if ((pipes->r1->type == START && pipes->r2->dist != -2) ||
				(pipes->r2->type == START && pipes->r1->dist != -2))
			return (0);
		pipes = pipes->next;
	}
	return (1);
}
