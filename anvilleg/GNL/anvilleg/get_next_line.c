/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/25 20:06:13 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		rfile(int fd, char *buf, char **line)
{
	ssize_t		bytes;
	static char	*copybuf;
	char		*temp;
	int			i;
	char		*aux;

	if (!copybuf)
		copybuf = NULL;
	temp = NULL;
	while (buf)
	{
		i = 0;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(copybuf);
			copybuf = NULL;
			free(buf);
			buf = NULL;
			return (-1);
		}
		else if (bytes > 0 || ft_strlen(copybuf) > 0)
		{
			buf[bytes] = '\0';
			aux = ft_strjoin(copybuf, buf);
			free(buf);
			buf = NULL;
			free(copybuf);
			copybuf = NULL;
			copybuf = ft_strdup(aux);
			free(aux);
			aux = NULL;
			buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			while (copybuf[i] != '\n' && copybuf[i])
				i++;
			if (copybuf[i] == '\n' || (copybuf[i] == 0 && bytes == 0))
			{
				if (temp)
					free(temp);
				if (copybuf[i] == '\n')
					temp = ft_strdup(&copybuf[i + 1]);
				else
					temp = ft_strdup("");
				*line = ft_substr(copybuf, 0, i);
				if (!(*line))
					return (-1);
				free(copybuf);
				copybuf = NULL;
				if (temp)
				{
					copybuf = ft_strdup(temp);
					free(temp);
					temp = NULL;
				}
				break ;
			}
		}
		else if (bytes == 0)
		{
			*line = ft_strdup("");
			free(copybuf);
			copybuf = NULL;
			free(buf);
			buf = NULL;
			return (0);
		}
	}
	if (bytes == 0 && ft_strlen(copybuf) == 0 && i)
	{
		if (!(*line))
			*line = ft_strdup("");
		if (!copybuf)
		{
			free(copybuf);
			copybuf = NULL;
		}
		free(buf);
		buf = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	return (rfile(fd, buf, line));
}
