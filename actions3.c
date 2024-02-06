/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:08 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/06 23:28:47 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	if (*stack_b == NULL)
		return ;
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_node);
	write(1, "pa\n", 3);
}
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	if (*stack_a == NULL)
		return ;
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_node);
	write(1, "pb\n", 3);
}
