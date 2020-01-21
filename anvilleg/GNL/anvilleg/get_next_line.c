/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:26 by anvilleg          #+#    #+#             */
/*   Updated: 2020/01/21 12:26:34 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int get_next_line(int fd, char **line)
{
	ssize_t bytes;
	
	if (fd == -1)
	{
		printf("Error al abrir");
	}
	else
	{
		printf("fd: %d",fd);

		bytes = read(fd, *line, 5);
		close(fd);
		if (bytes == 0)
			printf("Archivo vacio \n");
		else 
			printf("Caracteres %zd, %s \n", bytes, *line);
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
	fd = open("./hola.txt", O_RDONLY);
	printf("%d",fd);
//	get_next_line(fd,line);
	ssize_t bytes;
	char buf[10];

    if (fd == -1)
    {
        printf("Error al abrir");
    }
    else
    {
        printf("fd: %d \n",fd);

        bytes = read(fd, buf, 5);
        close(fd);
        if (bytes == 0)
            printf("Archivo vacio \n");
        else
            printf("Caracteres %zd, %s \n", bytes, buf);
    }
    return 0;
}
