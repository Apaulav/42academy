/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/10 20:36:37 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int rfile(int fd, char *buf,char *copybuf)
{
	ssize_t bytes;
	char *temp;

	if (!copybuf)
		copybuf = ft_strdup("");
	temp = copybuf;
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 1 )
    {
		free(buf);
		printf("Archivo vacio \n");
        return (0);
	}
	else
    {
    	buf[bytes] = '\0';
		copybuf = ft_strjoin(copybuf, buf);
        printf("Caracteres: %zd \nArchivo: \n%s", bytes, buf);
		printf("\ncopy: %s",copybuf);
		//free(temp);
		return(1);
	}
	//return (0);
}
*/

int get_next_line(int fd, char **line)
{
	//recived fd and create buffer(used for keep the text reading.)
	char *buf;
	//declarar varible estática
	static char *copybuf;

	if (fd == -1)
	{
		printf("Error al abrir archivo.\n");
		return (-1);
	}
	else
	{
		//comprobar con if si se ha encontrado \n en la varible estática (crear función quiza puedo usar strchr)
		//while (variables estática exista hace recorrer)
		//{
			//if (varible estática == '\n')
				//si se encuentra '\n' llamo a función asignar **line
		//}
		buf = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
		if (buf == NULL)
			return (-1);
		//rfile(fd, buf,copybuf);
		ssize_t bytes;
		char *temp;
		
		if (!copybuf)
			copybuf = ft_strdup("");
		temp = copybuf;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 1 )
		{
			free(buf);
			printf("Archivo vacio \n");
			return (0);
		}
		else
		{
			buf[bytes] = '\0';
			copybuf = ft_strjoin(copybuf, buf);
			printf("Caracteres: %zd \nArchivo: \n%s", bytes, buf);
			printf("\ncopy: %s",copybuf);
			//free(temp);
			return(1);
		}
		//Llamo a función asignar **line
	}
}

int main(int argc, char **argv)
{
//	char *str;

//	if(get_next_line(1,&str) != -1)
//		printf("%s", str);
	int fd;
	char *line = NULL;
	argc++;	
	//abro archivo como solo lectura (O_RDONLY) y me devuelve el fd
	fd = open(argv[1], O_RDONLY);
	printf("FD: %d \n",fd);
	get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	close(fd);

}
