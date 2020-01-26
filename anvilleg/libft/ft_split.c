/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:28:37 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/12 10:02:11 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_frag(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		i = (s[i] ? i + 1 : i);
	}
	return (j);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	int		z;

	if (!s)
		return (NULL);
	ptr = (char **)(ft_calloc(ft_num_frag(s, c) + 1, sizeof(char *)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[z++] = ft_substr(s, j, i - j);
		}
		i = (s[i] ? i + 1 : i);
	}
	return (ptr);
}
