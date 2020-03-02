/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:55 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/02 23:17:23 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		validate(ssize_t bytes, char **copybuf, int i, char **line)
{
	if (bytes == 0 && ft_strlen(*copybuf) == 0 && i)
	{
		if (!(*line))
		{
			*line = ft_strdup("");
			free(*copybuf);
			copybuf = NULL;
		}
		return (0);
	}
	return (1);
}

static int		jump(char *buf, char **copybuf, char **line, ssize_t bytes)
{
	int				i;
	char			*temp;

	i = 0;
	buf[bytes] = '\0';
	temp = ft_strjoin(*copybuf, buf);
	free(*copybuf);
	*copybuf = temp;
	while (*(*copybuf + i) != '\n' && *(*copybuf + i))
		i++;
	if (*(*copybuf + i) == '\n' || (*(*copybuf + i) == 0 && bytes == 0))
	{
		temp = (*(*copybuf + i) == '\n') ? ft_strdup((*copybuf + i + 1))
			: ft_strdup("");
		*line = ft_substr(*copybuf, 0, i);
		if (!(*line))
			return (-1);
		free(*copybuf);
		*copybuf = temp;
		return (validate(bytes, copybuf, i, line) == 0 ? 0 : 1);
	}
	return (i + 1);
}

static	int		rfile(int fd, char **copybuf, char *buf, char **line)
{
	ssize_t			bytes;
	int				j;

	while (buf)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		else if (bytes > 0 || ft_strlen(*copybuf) > 0)
		{
			j = jump(buf, copybuf, line, bytes);
			if (j == 1 || j == 0)
				return (j);
		}
		else if (bytes == 0 && ft_strlen(*copybuf) == 0)
		{
			free(*copybuf);
			*copybuf = NULL;
			*line = ft_strdup("");
			if (!*line)
				return (-1);
			return (0);
		}
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char	*copybuf;
	char		*buf;
	int			gnl;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (copybuf == NULL)
		copybuf = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	gnl = rfile(fd, &copybuf, buf, line);
	free(buf);
	buf = NULL;
	return (gnl);
}
