/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:16:19 by anvilleg          #+#    #+#             */
/*   Updated: 2019/11/30 04:51:35 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *aux;
	unsigned char *aux2;

	i = 0;
	aux = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while ((i < (n - 1)) && aux[i] != '\0')
	{
		i++;
	}
	size_t j;
	j = 0;
	while (j < (n-1) && aux[i] != '\0')
	{
		j++;
	}
//	printf("%c\n",aux[i]);
//	printf("%c\n",aux[j]);
//	printf("%d\n",(aux[i] -aux2[j]));
	return (aux[i] - aux2[j]);
}
/*
int main()
{
	char s1a[15] = "anvnvnvola";
	//unsigned char *s1b;
	char *s2  = "bbcdef";
	size_t n;
	//s1b[15] = "hola";
	n = 1;
	printf("%d\n", memcmp(s1a,s2,n));
	printf("%d\n", ft_memcmp(s1a,s2,n));
}*/
