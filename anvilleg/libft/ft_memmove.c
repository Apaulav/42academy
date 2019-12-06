/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:50:52 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/04 08:07:13 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
 
// Copias len personajes del objeto apuntado por src al objeto apuntado por dest. 
// Los objetos pueden superponerse: la copia se lleva a cabo como si los personajes 
// se copiaron en una matriz de caracteres temporal y los personajes fueron copiados 
// de la matriz a dest. Si los objetos no son trivialmente-copiable 
// (escalares, arrays estilo C-estructuras), el comportamiento no está definido.

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *aux;
	unsigned char *aux2;
	size_t i;

	aux = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	i = 0;
	if (aux2 < aux)
	{
		while (i <= len)
		{
			aux[len - i] = aux2[len - i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*aux = *aux2;
			aux++;
			aux2++;
			len--;
		}
	}
	return (dst);
}

int main()
{
	char dst[255] = "hola";
	char src[255] = "adios";
	size_t len = 6;
	printf("memmove = %s\n", memmove(dst, src, len));
	printf("ft_memmove = %s", ft_memmove(src, src + 2, len));
}
