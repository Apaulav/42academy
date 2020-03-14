/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:05:38 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/09 12:26:33 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	int		length;
	char	*r;
	int		i;

	length = ft_strlen(s1) + 1;
	r = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (r != NULL)
	{
		while (i < length - 1)
		{
			r[i] = s1[i];
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*m;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (m == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		m[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		m[j++] = s2[i++];
	m[j] = '\0';
	return ((char *)m);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
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
	while (i < len && s[start])
	{
		m[i] = s[start];
		start++;
		i++;
	}
	m[i] = '\0';
	return (m);
}
