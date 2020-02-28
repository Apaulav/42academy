/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/27 23:05:19 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	clean(char *copybuf)
{
	if (!copybuf)
	{
		free(copybuf);
		copybuf = NULL;
	}
}

static	int		validate(ssize_t bytes, char *copybuf, int i, char **line)
{
	if (bytes == 0 && ft_strlen(copybuf) == 0 && i)
	{
		if (!(*line))
			*line = ft_strdup("");
		free(copybuf);
		copybuf = NULL;
		return (0);
	}
	return (1);
}

static int		jump(char *buf, char **copybuf, char **line, ssize_t bytes)
{
	char			*aux;
	int				i;
	char			*temp;

	i = 0;
	buf[bytes] = '\0';
	aux = ft_strjoin(*copybuf, buf);
	if (!copybuf)
		free(*copybuf);
	*copybuf = aux;
	while (*(*copybuf + i) != '\n' && *(*copybuf + i))
		i++;
	if (*(*copybuf + i) == '\n' || (*(*copybuf + i) == 0 && bytes == 0))
	{
		//temp = (*(*copybuf + i) == '\n') ? ft_strdup(&(*(*copybuf + i + 1)))
		temp = (*(*copybuf + i) == '\n') ? ft_strdup((*copybuf + i + 1))
			: ft_strdup("");
		*line = ft_substr(*copybuf, 0, i);
		if (!(*line))
			return (-1);
		free(*copybuf);
		*copybuf = ft_strdup(temp);
		free(temp);
		return (validate(bytes, *copybuf, i, line) == 0 ? 0 : 1);
	}
	return (i + 1);
}

static	int		rfile(int fd, char *buf, char **line)
{
	ssize_t			bytes;
	static char		*copybuf = NULL;
	int				j;

	if (!copybuf)
		copybuf = ft_strdup("");
	while (buf)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		else if (bytes > 0 || ft_strlen(copybuf) > 0)
		{
			j = jump(buf, &copybuf, line, bytes);
			if (j == 1)
				return (1);
			if (j == 0)
				return (0);
		}
		else if (bytes == 0)
		{
			*line = ft_strdup("");
			clean(copybuf);
			return (0);
		}
	}
	return (validate(bytes, copybuf, j, line) ? 0 : 1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			gnl;

if (fd == -1 || !line || BUFFER_SIZE <= 0)
	{
		//printf("Error al abrir archivo.\n");
		return (-1);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	gnl = rfile(fd, buf, line);
	free(buf);
	buf = NULL;
	return (gnl);
}
