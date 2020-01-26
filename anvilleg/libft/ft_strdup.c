/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:36:11 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/16 09:36:59 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*r;
	int		i;

	length = ft_strlen(s1) + 1;
	r = ft_calloc(length, sizeof(char));
	i = 0;
	if (r != NULL)
	{
		while (i < length - 1)
		{
			r[i] = s1[i];
			i++;
		}
		r[i] = 0;
	}
	return (r);
}
