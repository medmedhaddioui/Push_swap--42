/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medmed <medmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:29:57 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/15 00:48:31 by medmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int i)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int i)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int i)
{
	sa(stack_a, i);
	sb(stack_b, i);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	ra(t_list **stack_a, int i)
{
	t_list	*second_node;
	t_list	*first_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first_node = *stack_a;
	second_node = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = first_node;
	first_node->next = NULL;
	(*stack_a) = second_node;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int i)
{
	t_list	*second_node;
	t_list	*first_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_node = *stack_b;
	second_node = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = first_node;
	first_node->next = NULL;
	(*stack_b) = second_node;
	if (i == 0)
		write(1, "rb\n", 3);
}
