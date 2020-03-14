/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:58:51 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/12 00:30:59 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (m == 0)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (i < len)
	{
		m[i] = s[start];
		start++;
		i++;
	}
	m[i] = '\0';
	return (m);
}
