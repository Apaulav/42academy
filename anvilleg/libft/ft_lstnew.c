t_list	*ft_lstnew(void const *content)
{
	t_list *lista;
	
	lista = (t_list *) malloc(sizeof(t_list));
	if (!lista)
		return (0);
	if (content != 0)
	{
		lista -> content = (void *)content;
		lista -> next = NULL;
	}
	else
		lista -> content = NULL;	
	return (lista);

}
