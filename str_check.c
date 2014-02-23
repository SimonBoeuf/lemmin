/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 21:43:47 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 23:11:06 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

int		is_ant_number(char *str)
{
	if (get_anthill()->rooms != NULL)
		return (0);
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
	if (get_anthill()->pipes != NULL)
		return (0);
	if (!is_comment(str) && !strstart("L", str))
	{
		while (*str != ' ' && *str != '\t')
			str++;
		str++;
		if (*str == '-')
			str++;
		while (ft_isdigit(*str))
			str++;
		if (*str != ' ')
			return (0);
		str++;
		if (*str == '-')
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
	if (!is_comment(str) && !strstart("L", str) && !is_room(str))
	{
		ft_putendl(str);
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
