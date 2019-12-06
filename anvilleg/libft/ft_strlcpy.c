/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:41:28 by anvilleg          #+#    #+#             */
/*   Updated: 2019/11/19 01:20:51 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		if (dstsize != 0 && j < (dstsize - 1))
		{
			dst[j] = (char)src[j];
			j++;
		}
		i++;
	}
	if ((j > 0) || (*src == 0))
		dst[j] = '\0';
	return (i);
}
