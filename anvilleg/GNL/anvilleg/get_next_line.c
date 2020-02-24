/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/24 16:46:13 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int rfile(int fd, char *buf, char **line)
{
	ssize_t bytes;
	static char *copybuf;
	char *temp;
    int i;

	if (!copybuf)
		copybuf = ft_strdup(""); //Compruebo si copybuf está vacio y lo inicializo
	temp = ft_strdup("");
	while (buf)
	{
		i = 0;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0 && ft_strlen(copybuf) <= 0)
			return (-1);
		else if (bytes > 0 || ft_strlen(copybuf) > 0)
        {
			printf("\033[1;35mcopybuf: %s\033[0m\n", copybuf);
            buf[bytes] = '\0';
            copybuf = ft_strjoin(copybuf, buf);
			free(buf);
			buf = 0;
            while (copybuf[i] != '\n' && copybuf[i])
                i++;
            if (copybuf[i] == '\n' || (copybuf[i] == 0 && bytes == 0))
            {
                copybuf[i] = '\0';
				free(temp);
				temp = NULL;
				temp = ft_strdup(&copybuf[i + 1]);
                *line = ft_substr(copybuf,0,i+1);
				free(copybuf);
				copybuf = NULL;
				if (temp)
				{
					//printf("\nentro\n");
					copybuf = ft_strdup(temp);
					free(temp);
					temp = NULL;
				}
				break;
            }
			/*else
			{
				*line = ft_strdup(copybuf);
				free(copybuf);
				return (0);
			}*/

        }
	}
	if (bytes <= 0 && ft_strlen(copybuf) <= 0)
	{
		free(copybuf);
		copybuf = NULL;
		return (0);
	}
	return (1);
}

int get_next_line(int fd, char **line)
{
	char *buf;
	
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
	{
	//	printf("Error al abrir archivo.\n");
		return (-1);
	}
	else
	{
		buf = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
		if (buf == NULL)
		{
			free(buf);
			buf = NULL;
			return (-1);
		}
		return (rfile(fd, buf,line));
	}
	return(0);
}
