/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:43:10 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 21:43:24 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

char	*get_room_name_pipe(char **line)
{
	char	*name;
	int		len;

	len = 0;
	while (line[0][len] && line[0][len] != '-')
		len++;
	name = ft_strnew(len);
	name = ft_strncpy(name, *line, len);
	*line += len + 1;
	return (name);
}

char	*get_room_name(char **line)
{
	char	*name;
	int		len;

	len = 0;
	while (line[0][len] && line[0][len] != ' ')
		len++;
	name = ft_strnew(len);
	name = ft_strncpy(name, *line, len);
	*line += len + 1;
	return (name);
}

int		get_coord(char **line)
{
	char	*coord;
	int		len;
	int		rslt;

	len = 0;
	while ((line[0][len] && ft_isdigit(line[0][len])) || line[0][len] == '-')
		len++;
	coord = ft_strnew(len);
	coord = ft_strncpy(coord, *line, len);
	*line += len + 1;
	rslt = ft_atoi(coord);
	return (rslt);
}

void	add_ants(void)
{
	char	*name;
	int		i;

	i = 1;
	while (i <= get_anthill()->ants)
	{
		name = ft_strnew(10);
		name = ft_strcat(name, "L");
		name = ft_strcat(name, ft_itoa(i));
		add_ant(name);
		i++;
	}
}
