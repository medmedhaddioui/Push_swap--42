/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:13 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/17 14:33:21 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_list *stack_a)
{
	t_list	*second;

	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content == second->content)
				return (0);
			second = second->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	num_arg(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1])
		i++;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
