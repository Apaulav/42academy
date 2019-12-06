/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:13:06 by anvilleg          #+#    #+#             */
/*   Updated: 2019/11/28 18:01:52 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//Localiza la primera aparición del carácter c (convertido a unsigned char) en los 
//primeros n caracteres (cada uno interpretado como un unsigned char) del objeto 
//apuntado por s.
//Devuelve NULL si no encuentra c.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *aux;
	size_t i;

	aux = (unsigned char *)s;
	c = (unsigned char)c;
	i = 0;
	while (*aux != c && i < n && *aux)
	{
		aux++;
		i++;
		//printf("%c", *aux);
	}
	if (i == n)
		return(0);
	else
		return ((void *)aux);
}
/*
int main()
{
	char s1[255] = "Erase una vez.....";
	char s2[255] = "Erase una vez.....";
	int c = 'u';
	size_t n = 10;
	printf("%s\n", memchr(s1,c,n));
	printf("%s\n", ft_memchr(s2,c,n));
}*/
