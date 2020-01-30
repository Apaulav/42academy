/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/01/30 13:51:40 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 32

int get_next_line(int fd, char **line)
{
	ssize_t bytes;
	char *buf;

	line = NULL;
	buf = NULL;
	bytes = 0;
	buf = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
	if (buf == NULL)
		return (-1);
	if (fd == -1)
	{
		printf("Error al abrir archivo.\n");
		return (-1);
	}
	else
	{
		bytes = read(fd, buf, BUFFER_SIZE);
//		buf[bytes] = '\0';
		if (bytes <= 1 )
		{
			printf("Archivo vacio \n");
			return (-1);
		}
		else 
		{
/*			line = (char **)malloc(sizeof(char)*BUFFER_SIZE);
			if (line == NULL)
				return (-1);
*/
			//mientras archivo no termine line [i][j]
			//mientras salto de linea no exista
			//devuelve line [i][j] y a j++
			// i++
			int i = 0;
			int j = 0;
			int h = 0;
			while (h < bytes)//buf[h] != '\0' /*h < 23*/)
			{
				while (buf[h] != '\n' && h < bytes)
				{
				//line[0][0] = buf[0];
					printf("Buf: %c\n", buf[h]);
//					write(1,buf+h,1);
//					write(1,"\n",1);
				//printf("%s",line[0][0]);
					j++;
					h++;
				}
				h++;
				i++;
				j=0;
			}
//			int i = 0;
//			printf("i:%d", i);
			printf("Caracteres: %zd \nArchivo: \n%s", bytes, buf);
//			i++;
//			printf("i:%d", i);
		}
	}
	close(fd);
	free(buf);
	free(line);
	return 0;
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
}
