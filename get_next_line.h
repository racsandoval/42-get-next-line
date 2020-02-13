/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:56:51 by marvin            #+#    #+#             */
/*   Updated: 2020/02/13 13:56:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char**line);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif