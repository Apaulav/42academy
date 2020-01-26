/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/01/26 18:49:25 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int get_next_line(int fd, char **line)
{
	ssize_t bytes;
	char buf[50];

	line = 0;
	if (fd == -1)
	{
		printf("Error al abrir archivo.");
	}
	else
	{
		bytes = read(fd, buf, 50);
		close(fd);
		if (bytes == 1 )
			printf("Archivo vacio \n");
		else 
			printf("Caracteres: %zd \nArchivo: \n%s \n", bytes, buf);
	}
	return 0;
}

int main()
{
//	char *str;

//	if(get_next_line(1,&str) != -1)
//		printf("%s", str);
	int fd;
	char **line;	
	//abro archivo como solo lectura (O_RDONLY) y me devuelve el fd
	fd = open("./archivo.txt", O_RDONLY);
	printf("FD: %d \n",fd);
	get_next_line(fd, line);
}
