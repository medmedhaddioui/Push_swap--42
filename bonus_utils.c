/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:10:36 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/14 15:23:11 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void free_stack(t_list **stack_a)
{
	ft_lstclear(stack_a);
	ft_exit();
}
int sort_check(t_list *stack_a)
{
	t_list	*second;

	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content > second->content)
				return 0;
			second = second->next;
		}
		stack_a = stack_a->next;
	}
	return 1;
}