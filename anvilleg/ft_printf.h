/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:45:28 by anvilleg          #+#    #+#             */
/*   Updated: 2020/03/10 04:39:18 by anvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef	struct	s_printf
{
	char	*str;
	int		cont;
	va_list	ap;
}				t_printf;

int     ft_printf(const char *format, ...);

#endif
