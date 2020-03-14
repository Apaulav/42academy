/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:55 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/09 12:24:55 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		jump(char **copybuf, char **line)
{
	int			i;
	char		*temp;

	i = 0;
	while (*(*copybuf + i) != '\n' && *(*copybuf + i))
		i++;
	if (*(*copybuf + i) == '\n')
	{
		temp = ft_strdup((*copybuf + (i + 1)));
		*line = ft_substr(*copybuf, 0, i);
		free(*copybuf);
		*copybuf = temp;
		if (*copybuf[0] == '\0')
		{
			free(*copybuf);
			*copybuf = NULL;
		}
		return (1);
	}
	else
	{
		*line = ft_strdup(*copybuf);
		return (0);
	}
	return (2);
}

static	int		rfile(int fd, char **copybuf, char *buf, char **line)
{
	ssize_t		bytes;
	char		*aux;

	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (*copybuf == NULL)
			*copybuf = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(*copybuf, buf);
			free(*copybuf);
			*copybuf = aux;
		}
		if (ft_strchr(*copybuf, '\n'))
			return (1);
	}
	if (bytes < 0 || (*copybuf == NULL && bytes == 0))
	{
		if (bytes < 0)
			return (-1);
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*copybuf;
	char		*buf;
	int			gnl;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	gnl = rfile(fd, &copybuf, buf, line);
	if (gnl == 1)
		gnl = jump(&copybuf, line);
	if (gnl == 0 || gnl == -1)
	{
		if (copybuf)
		{
			free(copybuf);
			copybuf = NULL;
		}
	}
	free(buf);
	buf = NULL;
	return (gnl);
}
