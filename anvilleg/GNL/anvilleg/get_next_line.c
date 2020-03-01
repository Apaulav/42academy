/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:55 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/01 17:43:20 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static	void	clean(char *clear)
{
	//if (ft_strlen (clear) > 0)
	//{
		free(clear);
		clear = NULL;
	//}
}*/

static	int		validate(ssize_t bytes, char *copybuf, int i, char **line)
{
	if (bytes == 0 && ft_strlen(copybuf) == 0 && i)
	{
		if (!(*line))
			*line = ft_strdup("");
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
	*copybuf = NULL;
	*copybuf = temp;
	//free(temp);
	while (*(*copybuf + i) != '\n' && (*(*copybuf + i) != '\0'))
		i++;
	if (*(*copybuf + i) == '\n' || (*(*copybuf + i) == 0 && bytes == 0))
	{
		temp = (*(*copybuf + i) == '\n' && ft_strlen(*copybuf) > 0) ?
		ft_strdup((*copybuf + i + 1)) : ft_strdup("");
		*line = ft_substr(*copybuf, 0, i);
		//*copybuf[i]= '\0';
		if (!(*line))
			return (-1);
		if (!copybuf)
			free(*copybuf);
		*copybuf = ft_strdup(temp);
		free(temp);
		temp = NULL;
		return (validate(bytes, *copybuf, i, line) == 0 ? 0 : 1);
	}
	return (i + 1);
}

static	int		rfile(int fd, char *buf, char **line, char **copybuf)
{
	ssize_t			bytes;
	int				j;

	while (buf)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		else if (bytes > 0 || ft_strlen(*copybuf) > 0 ||
		buf[0] == '\n' || *copybuf[0] == '\n')
		{
			j = jump(buf, copybuf, line, bytes);
			if (j == 1)
				return (1);
			if (j == 0)
				return (0);
		}
		else if (bytes == 0)
		{
			*line = ft_strdup("");
			//clean(*copybuf);
			return (0);
		}
	}
	return (validate(bytes, *copybuf, j, line) ? 0 : 1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*copybuf = NULL;
	int			gnl;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	if (copybuf == NULL)
		copybuf = ft_strdup("");
	gnl = rfile(fd, buf, line, &copybuf);
	free(buf);
	buf = NULL;
	if (gnl == 0)
	{
		if (!(*line))
			*line = ft_strdup("");
		free(copybuf);
		copybuf = NULL;
	}
	return (gnl);
}
