/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pau <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:35:59 by pau               #+#    #+#             */
/*   Updated: 2019/12/27 13:05:38 by pau              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void const *content)
{
	t_list *lista;
	int size;
	
	size = ft_strlen(content);
	lista = (t_list *)malloc(size * sizeof(t_list));
	if (!lista)
		return (0);
	if (content != 0)
	{
		lista->content = (void *)content;
		lista->next = NULL;
	}
	else
		lista -> content = NULL;	
	return (lista);

}

int main()
{
	t_list *lista = ft_lstnew("hola");
	printf("%s", lista);
	return(0);
}
