/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/18 05:18:33 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char clean(char *string)
{
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (*string);
}*/

int rfile(int fd, char *buf, char **line)
{
	ssize_t bytes;
	static char *copybuf;
	char *temp;
//	int m;
    int i;
//	int l;
//	int t;

	if (!copybuf)
		copybuf = ft_strdup("");
//	printf("longitud copybuf: %d\n", ft_strlen(copybuf));
	//temp = ft_strdup("");
	i = 0;
	while (buf)
	{
		//i = ft_strlen(copybuf);
		//printf("longitud2 copybuf: %d\n", ft_strlen(copybuf));
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{	
			free(buf);
			buf = NULL;
			free(copybuf);
			copybuf = NULL;
			return (-1);
		}
		else if (bytes == 0 )
    	{
			free(buf);
			buf = NULL;
			free(copybuf);
			copybuf = NULL;
			//clean(buf);
			//clean(copybuf);
			printf("Archivo vacio \n");
        	return (0);
		}
		else
	    {
    		buf[bytes] = '\0';
			printf("Leido: %s\n",buf);
			copybuf = ft_strjoin(copybuf, buf);
//        	printf("Caracteres leidos: %zd\nleido: %s\n", bytes, buf);
			printf("copia: %s\n",copybuf);
			//printf("salto: %s\n",ft_strchr(copybuf,'\n'))    ;
			//otra función comprobar \n
            //t = ft_strlen(temp);
			//printf("t: %d\n",t);
			while (copybuf[i] != '\n' && copybuf[i])
			{
				//temp[t] = copybuf[i];
				//printf("i: %c\n",copybuf[i]);
                i++;
				//t++;
            }
			//t++;
			//temp[t] = '\0';
            if (copybuf[i] == '\n')
            {

	        	//m = i+1;
				printf("Salto de línea encontrado en la posicion: %d\n", i);
				//line = (char **)malloc(sizeof(char *)*m);
				//if (line == NULL)
				//	return (-1);
				//l = 0;
				//t = 0;
				//while (temp[t] != '\0')
				//{
				//	line[0][l] = temp[t];
				//	t++;
				//	l++;
				//}

				temp = ft_strdup(&copybuf[i + 1]);
				printf("temp despues: %s\n",temp);
				//printf("temporal:%s\n", temp);
				*line = ft_substr(copybuf,0,i);	
				//line = ft_strdup(temp);
				//free(temp);
				printf("Line: %s\n",*line);
				//copybuf[i]='\0';
				printf("copia sin \\n: %s\n",temp);
				break;

            }
		}
	}
	//clean(copybuf);
	free(copybuf);
	copybuf = NULL;
	//printf("Liberado copy %s\n",copybuf);
	copybuf = ft_strdup(temp);
	//printf("Liberado copy %s\n",copybuf);
	return (1);
}

int get_next_line(int fd, char **line)
{
	//recived fd and create buffer(used for keep the text reading.)
	char *buf;
		
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
		rfile(fd, buf,line);
		//Llamo a función asignar **line
	}
	return(0);
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
	printf("Primer gnl\n");
	get_next_line(fd, &line);
	printf("Segundo gnl\n");
	get_next_line(fd, &line);
	printf("Tercer gnl\n");
	get_next_line(fd, &line);
	printf("cuarto gnl\n");
	get_next_line(fd, &line);
	//close(fd);
}
