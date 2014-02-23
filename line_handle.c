/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:43:03 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 23:11:08 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

int		handle_line(char *line)
{
	if (is_comment(line))
		handle_comment(line);
	else if (is_ant_number(line))
		handle_ants(line);
	else if (is_room(line))
		handle_room(line, COMMON);
	else if (is_pipe(line))
		handle_pipe(line);
	else
		return (0);
	return (1);
}

void	handle_ants(char *s)
{
	t_anthill	*r;

	ft_putendl(s);
	r = get_anthill();
	r->ants = ft_atoi(s);
	r->ants_left = ft_atoi(s);
}

void	handle_comment(char *s)
{
	int			r;
	t_rtype		type;
	char		*line;

	ft_putendl(s);
	type = (!ft_strcmp(s, "##start")) ? START : COMMON;
	if (type != START)
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

	while (!is_room(s))
	{
		ft_putendl(s);
		if (get_next_line(0, &s) <= 0)
			exit (-1);
	}
	ft_putendl(s);
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

	ft_putendl(s);
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
