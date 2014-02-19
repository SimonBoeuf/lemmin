#include "includes/lemmin.h"

int		handle_line(char *line)
{
	if (is_ant_number(line))
		handle_ants(line);
	else if (is_comment(line))
		handle_comment(line);
	else if (is_room(line))
		handle_room(line, COMMON);
	else if (is_pipe(line))
		handle_pipe(line);
	else
		return (0);
	ft_putendl(line);
	return (1);
}

void	handle_ants(char *s)
{
	t_anthill	*r;
	r = get_anthill();
	r->ants = get_ant_number(s);
}

void	handle_comment(char *s)
{
	int			r;
	t_rtype		type;
	char		*line;

	type = (!ft_strcmp(s, "##start")) ? START : COMMON;
	type = (!ft_strcmp(s, "##end")) ? END : COMMON;
	if (type != COMMON)
	{
		if ((r = get_next_line(0, &line)) > 0)
			handle_room(line, type);
		if (r == -1)
			strerror(errno);
	}
}

void	handle_room(char *s, t_rtype type)
{
	char	*name;
	int		x;
	int		y;

	name = get_room_name(&s);
	x = get_coord(&s);
	y = get_coord(&s);
	add_room(name, x, y, type);
}

void	handle_pipe(char *s)
{
	char	*name1;
	char	*name2;
	t_room	*r1;
	t_room	*r2;

	name1 = get_room_name_pipe(&s);
	name2 = get_room_name_pipe(&s);
	r1 = find_room(name1);
	r2 = find_room(name2);
	if (r1 == NULL || r2 == NULL)
	{
		ft_putendl("Error : room not found");
		exit(-1);
	}
	add_pipe(r1, r2);
}
