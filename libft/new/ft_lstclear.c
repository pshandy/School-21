/*
 * void	ft_lstclear(t_list **lst, void (*del)(void *))
 *
 * Deletes and frees the given element and every
 * successor of that element, using the function ’del’
 * and free(3).
 * Finally, the pointer to the list must be set to
 * NULL.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	l = *lst;
	tmp = NULL;
	while (*l)
	{
		if (l->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(l);
		l = tmp;
	}
}
