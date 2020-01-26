/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 05:15:37 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/12 09:18:08 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_inicio(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static	size_t		ft_final(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (set[j] == '\0')
			return (i + 1);
		i--;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	i;
	size_t	f;
	size_t	len;

	if (!s1)
		return (0);
	i = ft_inicio(s1, set);
	f = ft_final(s1, set);
	if (f > i)
		len = f - i;
	else
		len = 0;
	m = ft_substr(s1, i, len);
	return (m);
}
