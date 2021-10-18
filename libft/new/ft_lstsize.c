/*
 * int		ft_lstsize(t_list *lst)
 *
 * Counts the number of elements in a list.
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*it;

	len = 0;
	it = lst;
	while (it)
	{
		len++;
		it = it->next;
	}
	return (len);
}
