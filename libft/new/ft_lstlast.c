/*
 * t_list	*ft_lstlast(t_list *lst)
 *
 * Returns the last element of the list.
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	t = lst;
	while (lst->next)
		lst = lst->next;
	return (lst);
}
