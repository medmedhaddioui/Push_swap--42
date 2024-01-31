#include "push_swap.h"
void	ft_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		del(&(ptr->content));
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}
void del (int *content)
{
	free(content);
	return;
}