/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:56:53 by marvin            #+#    #+#             */
/*   Updated: 2020/02/13 13:56:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char *str, int lb)
{
	char	*tmp;
	int		i;

	tmp = malloc(lb + 2);
	i = 0;
	while (i <= lb)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	get_line_break(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*send_line(char *str, int lb, char **line)
{
	char	*tmp;

	tmp = get_line(str, lb);
	*line = tmp;
	return (ft_strdup(&str[get_line_break(str) + 1]));
}

char	*init_str(char	*str)
{
	if (!str)
	{
		str = malloc (1);
		str[0] = '\0';
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			r_num;

	str = init_str(str);
	if (fd < 0 || (read(fd, str, 0)) < 0 || !line)
		return (-1);
	while (get_line_break(str) == -1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!(r_num = read(fd, tmp, BUFFER_SIZE)))
		{
			str = send_line(str, ft_strlen(str), line);
			free(tmp);
			return (0);
		}
		tmp[r_num] = '\0';
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	if (get_line_break(str) != -1)
	{
		str = send_line(str, get_line_break(str), line);
		return (1);
	}
}