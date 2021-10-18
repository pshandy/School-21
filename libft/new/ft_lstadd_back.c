/*
 * void	ft_lstadd_back(t_list **lst, t_list *new)
 *
 * Adds the element ’new’ at the end of the list.
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = ft_lstlast(*lst);
	t->next = new;
}
