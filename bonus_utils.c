/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medmed <medmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:10:36 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/15 15:39:34 by medmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void free_stacks(t_list **stack_a, t_list **stack_b)
{
	
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}
int ft_sort_stack(t_list *stack_a)
{
	t_list	*second;

	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content > second->content)
			{
				stack_a->next = second->next;
				second->next = stack_a;
				stack_a = second;
				break;
			}
			second = second->next;
		}
		stack_a = stack_a->next;
	}
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}