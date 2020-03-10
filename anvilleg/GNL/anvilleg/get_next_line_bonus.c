/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:55 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/09 11:59:01 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*fdelete(char *aux)
{
	free(aux);
	aux = NULL;
	return (aux);
}

static	int		jump(char **copybuf, char **line, int fd)
{
	int			i;
	char		*temp;

	i = 0;
	while (copybuf[fd][i] != '\n' && (copybuf[fd][i]))
		i++;
	if ((copybuf[fd][i]) == '\n')
	{
		temp = ft_strdup((copybuf[fd] + (i + 1)));
		*line = ft_substr(copybuf[fd], 0, i);
		free(copybuf[fd]);
		copybuf[fd] = temp;
		if (copybuf[fd][0] == '\0')
		{
			free(copybuf[fd]);
			copybuf[fd] = NULL;
		}
	}
	else
	{
		*line = ft_strdup(copybuf[fd]);
		copybuf[fd] = fdelete(copybuf[fd]);
		return (0);
	}
	return (1);
}

static	int		rfile(int fd, char **copybuf, char *buf, char **line)
{
	ssize_t		bytes;

	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (copybuf[fd] == NULL)
			copybuf[fd] = ft_strdup(buf);
		else
			copybuf[fd] = ft_strjoin(copybuf[fd], buf);
		if (ft_strchr(copybuf[fd], '\n'))
			return (1);
	}
	if (bytes < 0 || (copybuf[fd] == NULL && bytes == 0))
	{
		if (bytes < 0)
			return (-1);
		*line = ft_strdup("");
		free(copybuf[fd]);
		copybuf[fd] = NULL;
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
		gnl = jump(&copybuf, line, fd);
	free(buf);
	buf = NULL;
	return (gnl);
}
