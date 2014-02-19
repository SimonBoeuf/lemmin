#include "includes/lemmin.h"

void	lemmin(void)
{
	get_map();
	find_paths();
	resolve();
}

void	get_map(void)
{
	int		r;
	char	*line;
	int		map;

	map = 1;
	while ((r = get_next_line(0, &line)) > 0 && map)
		map = handle_line(line);
	if (r == -1)
		strerror(errno);
	
}

void	find_paths(void)
{

}

void	resolve(void)
{

}
