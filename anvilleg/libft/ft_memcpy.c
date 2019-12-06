/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:08:14 by anvilleg          #+#    #+#             */
/*   Updated: 2019/11/26 23:29:35 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*aux;
	char	*aux2;

	i = 0;
	aux = (char *)dst;
	aux2 = (char *)src;
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	else
	{
		while (i < n)
		{
			aux[i] = aux2[i];
			i++;
		}
		return ((void *)dst);
	}
}
