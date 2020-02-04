/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/02/04 19:46:43 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int rfile(int fd, char *buf)
{
	ssize_t bytes;
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 1 )
    {
    	printf("Archivo vacio \n");
        return (0);
	}
	else
    {
    	buf[bytes] = '\0';
        int j = 0;
        int h = 0;
        while (buf[h] != '\n' && h < bytes)
        {
        	printf("Buf: %c\n", buf[h]);
            j++;
            h++;
		}
        printf("Caracteres: %zd \nArchivo: \n%s", bytes, buf);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char *buf;

	line = NULL;
	buf = NULL;
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
		rfile(fd, buf);
	}
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
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	close(fd);

}
