#include "includes/lemmin.h"

t_pipe	*new_pipe(t_room *r1, t_room *r2)
{
	t_pipe	*p;

	p = (t_pipe*)malloc(sizeof(t_pipe));
	p->r1 = r1;
	p->r2 = r2;
	p->next = NULL;
	return (p);
}

void	add_pipe(t_room *r1, t_room *r2)
{
	t_anthill	*anthill;
	t_pipe		*pipes;
	t_pipe		*new;

	anthill = get_anthill();
	pipes = anthill->pipes;
	new = new_pipe(r1, r2);
	if (pipes == NULL)
		anthill->pipes = new;
	else
	{
		while (pipes->next != NULL)
			pipes = pipes->next;
		pipes->next = new;
	}
}
