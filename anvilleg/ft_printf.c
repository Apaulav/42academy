/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:13:24 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/10 17:10:32 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf p;
	va_start(p.ap, format);
	p.str = (char *)format;
	while (*p.str)
	{
		if (*p.str == '%')
		{
			p.str++;
			if (*p.str == '%') //’-0.*’
				write (1, "%", 1);
			if(*p.str == 'c')
				write(1, p.str, 1);
				//spdiuxX
		}
		else
			write(1, p.str, 1);
		p.str++;
	}

	va_end(p.ap);
	return (0);
}
