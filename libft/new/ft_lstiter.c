/*
 * void	ft_lstiter(t_list *lst, void (*f)(void *))
 *
 * Iterates the list ’lst’ and applies the function
 * ’f’ to the content of each element.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (*lst)
	{
		f(lst);
		lst = lst->next;
	}
}
