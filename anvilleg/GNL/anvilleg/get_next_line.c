/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/25 00:11:13 by anvilleg         ###   ########.fr       */
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
		//printf("longitud2 copybuf: %zu\n", ft_strlen(copybuf));
		bytes = read(fd, buf, BUFFER_SIZE);
		printf("%ld", bytes);
		if (bytes < 0/* && ft_strlen(copybuf) <= 0*/)
			return (-1);
		else if (bytes > 0 || ft_strlen(copybuf) > 0)
        {
            buf[bytes] = '\0';
            //printf("Leido: %ld \"%s\"\n",bytes,buf);
            //printf("co+le: \"%s-%s\"\n", copybuf,buf);
            copybuf = ft_strjoin(copybuf, buf);
            //printf("copia: \"%s\"\n\n",copybuf);
            while (copybuf[i] != '\n' && copybuf[i])
                i++;
            //printf("temp despues: %s\n",temp);
            if (copybuf[i] == '\n' || (copybuf[i] == 0 && bytes == 0))
            {
                //printf("%c", copybuf[i]);
				free(temp);
				if (copybuf[i] == '\n')
				{
					printf("pene");
					temp = ft_strdup(&copybuf[i + 1]);
				}
				else
				{
					printf("vagina");
					temp  = ft_strdup("");
				}
				if (!temp)
				{
					return (-1);
				}
                //copybuf[i] = '\0';
               //printf("temporal: %s\n", temp);
                *line = ft_substr(copybuf,0,i);
				if (!(*line))
					return (-1);
                //printf("Line: %s\n",*line);
				free(copybuf);
				copybuf = NULL;
				if (temp)
				{
					copybuf = ft_strdup(temp);
					free(temp);
					temp = NULL;
				}
				break;
            }
        }
		else if (bytes == 0)
		{
			*line = ft_strdup("cacota");
			printf("zorra");
			free(copybuf);
			copybuf = NULL;
        	return (0);
		}
	}

	//printf("Se ha liberado la memoria\n");
	/*if (bytes == 0 && ft_strlen(copybuf) == 0)
	{	
		if (!(*line))
			*line = ft_strdup("");
	//		printf("Laputa");
		free(copybuf);
		copybuf = NULL;
		return (0);
	}*/
	return (1);
}

int get_next_line(int fd, char **line)
{
	//recived fd and create buffer(used for keep the text reading.)
	char *buf;
	//declarar varible estática
	
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
	{
		printf("Error al abrir archivo.\n");
		return (-1);
	}
	buf = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
	if (buf == NULL)
		return (-1);
	return (rfile(fd, buf,line));
		//Llamo a función asignar **line
}

/*int main(int argc, char **argv)
{
//	char *str;

//	if(get_next_line(1,&str) != -1)
//		printf("%s", str);
	int fd;
	char *line = NULL;

	argc++;
	//abro archivo como solo lectura (O_RDONLY) y me devuelve el fd
	fd = open(argv[1], O_RDONLY);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	free(line);
//	line = NULL;
	
	//	system("leaks a.out");
//	return (0);

	 while (get_next_line(fd, &line) >  0)
	{
		write(1, line, ft_strlen(line) + 1);
		write(1, "\n", 1);
	}	
//	//close(fd);
	return (0);
}*/
