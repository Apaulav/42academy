/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:39:37 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/06 00:13:51 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			write(fd, s + i, 1);
			i++;
		}
		s[i] = '\0';
		i++;
		s[i] = '\n';
		write(fd, s + i, 1);
	}
}
