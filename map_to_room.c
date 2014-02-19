#include "includes/lemmin.h"

char	*get_room_name(char **line)
{
	char	*name;
	int		len;

	len = 0;
	while (*line[len] && *line[len] != ' ')
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
	while (*line[len] && ft_isdigit(*line[len]))
		len++;
	coord = ft_strnew(len);
	coord = ft_strncpy(coord, *line, len);
	rslt = ft_atoi(coord);
	return (rslt);
}

