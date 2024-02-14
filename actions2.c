/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medmed <medmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:04 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/15 00:22:28 by medmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b, int i)
{
	ra(stack_a, i);
	rb(stack_b, i);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra(t_list **stack_a, int i)
{
	t_list	*tmp;
	t_list	*hold;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	hold = tmp->next;
	tmp->next = NULL;
	hold->next = *stack_a;
	(*stack_a) = hold;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int i)
{
	t_list	*tmp;
	t_list	*hold;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	hold = tmp->next;
	tmp->next = NULL;
	hold->next = *stack_b;
	(*stack_b) = hold;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int i)
{
	rra(stack_a, i);
	rrb(stack_b, i);
	if (i == 1)
		write(1, "rrr\n", 4);
}
