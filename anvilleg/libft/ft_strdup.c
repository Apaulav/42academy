/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:45:43 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/01 21:58:15 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
	char *m;
	int len;
	int i;
	
	len = ft_strlen(s1);
	m = malloc (len * sizeof(char) + 1);
	if (!m)
		return (0);
	i = 0;
	while (i < len)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
/*
int main()
{
	char s1[] = "hola";
}*/
