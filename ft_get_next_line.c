/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <wtrembla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 20:11:39 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/23 23:12:05 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemmin.h"

static char		*ft_line_read(char *str, int fin)
{
	size_t		i;
	char		*line;

	i = 0;
	while (str[i] != fin)
		i++;
	line = ft_strnew(i);
	i = 0;
	while (str[i] != fin)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	char			*tmp;
	static char		*str;
	char			fin;

	str = str == NULL ? ft_strdup("") : str;
	ret = 2;
	while ((tmp = ft_strdup(str)) && !(ft_strchr(tmp, '\n')))
	{
		if ((ret = read(fd, buf, BUF_SIZE)) == -1 || BUF_SIZE <= 0)
			return (-1);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (ret == 0 && *str == '\0')
			return (0);
		else if (ret == 0 && *str)
			break ;
	}
	fin = ret > 0 ? '\n' : '\0';
	*line = ft_line_read(str, fin);
	str = ft_strchr(str, '\n');
	str = str != NULL ? str + 1 : str;
	return (1);
}
