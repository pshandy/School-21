/*
 *void	ft_lstadd_front(t_list **lst, t_list *new)
 *
 * Adds the element ’new’ at the beginning of the
 * list.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
