/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:14:31 by anvilleg          #+#    #+#             */
/*   Updated: 2019/12/09 13:38:36 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int printer;
	long int k;

	printer = 0;
	k = (long int)n;
	if (k < 0)
	{
		k = -k;
		write(fd, "-", 1);
	}
	if (k >= 0 && k <= 9)
		printer = k + '0';
	if (k >= 10)
	{
		printer = k % 10 + '0';
		k = k / 10;
		ft_putnbr_fd(k, fd);
	}
	write(fd, &printer, 1);
}
