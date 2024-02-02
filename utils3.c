/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:44 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:45 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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