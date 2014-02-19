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

t_pipe	*get_pipes(t_pipe	*p)
{
	static t_pipe	*pipes = NULL;

	if (pipes == NULL)
		pipes = p;
	return (p);
}

void	add_pipe(t_room *r1, t_room *r2)
{
	t_pipe	*pipes;
	t_pipe	*new;

	pipes = get_pipes(NULL);
	new = new_pipe(r1, r2);
	if (pipes == NULL)
		get_pipes(new);
	else
	{
		while (pipes->next != NULL)
			pipes = pipes->next;
		pipes->next = new;
	}
}
