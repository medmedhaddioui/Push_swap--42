/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:29:51 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/10 15:49:13 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, 0);
}

void	sort_3(t_list **stack_a)
{
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content > (*stack_a)->next->next->content))
		ra(stack_a, 0);
	if ((((*stack_a)->next->next->content < (*stack_a)->content)
			&& ((*stack_a)->next->next->content < (*stack_a)->next->content))
		|| (((*stack_a)->next->next->content < (*stack_a)->next->content)
			&& ((*stack_a)->next->next->content > (*stack_a)->content)))
		rra(stack_a, 0);
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
		sa(stack_a, 0);
}

void	sort_4(t_list **stack_a, t_list **stack_b, int c)
{
	int	min_a;

	min_a = min(*stack_a);
	while (c > 0)
	{
		if ((*stack_a)->content == min_a)
		{
			pb(stack_a, stack_b);
			break ;
		}
		rra(stack_a, 0);
		c--;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b, int c)
{
	int	min_a;
	int	j;

	min_a = min(*stack_a);
	j = c;
	while (c > 0)
	{
		if ((*stack_a)->content == min_a)
		{
			pb(stack_a, stack_b);
			break ;
		}
		rra(stack_a, 0);
		c--;
	}
	sort_4(stack_a, stack_b, j);
	pa(stack_a, stack_b);
}
