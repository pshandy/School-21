/*
 * void *ft_memchr(const void *s, int c, size_t n)
 *
 * Allocates (with malloc(3)) and returns a new
 * element. The variable ’content’ is initialized
 * with the value of the parameter ’content’. The
 * variable ’next’ is initialized to NULL.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(t_list *));
	if (t == NULL)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}
