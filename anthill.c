#include "includes/lemmin.h"

t_anthill		*init_anthill(void)
{
	t_anthill	*anthill;

	anthill = (t_anthill*)malloc(sizeof(t_anthill));
	anthill->ants = 0;
	anthill->start = NULL;
	anthill->end = NULL;
	anthill->rooms = NULL;
	anthill->paths = NULL;
	return (anthill);
}

t_anthill		*get_anthill(void)
{
	static t_anthill	*anthill = NULL;

	if (anthill == NULL)
		anthill = init_anthill();
	return (anthill);
}