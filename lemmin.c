#include "includes/lemmin.h"

void	lemmin(void)
{
	int		r;
	char	*line;
	int		map;
	t_anthill	*ro;

	map = 1;
	while ((r = get_next_line(0, &line)) > 0 && map)
		map = handle_line(line);
	if (r == -1)
		strerror(errno);
	ro = get_anthill();
}
