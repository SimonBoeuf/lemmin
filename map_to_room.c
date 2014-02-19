#include "includes/lemmin.h"

int		get_ant_number(char *line)
{
	int	rslt;
	int	i;

	rslt = 0;
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (!line[i])
		rslt = ft_atoi(line);
	return (rslt);
}

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
	while (line[0][len] && ft_isdigit(line[0][len]))
		len++;
	coord = ft_strnew(len);
	coord = ft_strncpy(coord, *line, len);
	*line += len + 1;
	rslt = ft_atoi(coord);
	return (rslt);
}

