/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:35:54 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/16 09:36:54 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	r;
	size_t	i;
	size_t	dstsize;

	dstsize = ft_strlen(dst);
	i = 0;
	if (n <= dstsize)
		r = (ft_strlen(src) + n);
	else
	{
		r = (dstsize + ft_strlen(src));
		while (i + dstsize + 1 < n && src[i])
		{
			dst[i + dstsize] = src[i];
			i++;
		}
		dst[i + dstsize] = 0;
	}
	return (r);
}
