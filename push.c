/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medmed <medmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:14:39 by medmed            #+#    #+#             */
/*   Updated: 2024/02/15 00:26:16 by medmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	if (*stack_b == NULL)
		return ;
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_node);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	if (*stack_a == NULL)
		return ;
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_node);
}