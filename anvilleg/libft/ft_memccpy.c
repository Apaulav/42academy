/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:22:54 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/01 13:40:26 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *aux;
	unsigned char *aux2;

	aux = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	while (n > 0)
	{
		*aux = *aux2;
		if (*aux2 == (unsigned char)c)
		{
			aux++;
			return (aux);
		}
		aux++;
		aux2++;
		n--;
	}
	return (NULL);
}
