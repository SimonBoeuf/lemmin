#include "includes/lemmin.h"

int		is_ant_number(char *str)
{
	if (*str)
	{
		while (ft_isdigit(*str))
		str++;
		return (!*str);
	}
	return (0);
}

int		is_comment(char *str)
{
	return (strstart("#", str));
}

int		is_room(char *str)
{
	if (!is_comment(str) && !strstart("L", str))
	{
		while (ft_isalnum(*str))
			str++;
		if (*str != ' ')
			return (0);
		str++;
		while (ft_isdigit(*str))
			str++;
		if (*str != ' ')
			return (0);
		str++;
		while (ft_isdigit(*str))
			str++;
		if (*str)
			return (0);
		return (1);
	}
	return (0);
}

int		is_pipe(char *str)
{
	if (!is_comment(str) && !strstart("L", str))
	{
		while (ft_isalnum(*str))
			str++;
		if (*str != '-')
			return (0);
		str++;
		while (ft_isalnum(*str))
			str++;
		if (*str)
			return (0);
		return (1);
	}
	return (0);
}

int		strstart(char *mask, char *str)
{
	int	i;

	i = 0;
	while (str[i] && mask[i] && str[i] == mask[i])
		i++;
	return (!mask[i]);
}
