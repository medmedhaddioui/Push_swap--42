/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:13 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/09 17:13:22 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int  dup_arg (t_list *stack_a)
{
	t_list *second;
	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content == second->content)
				return 1;
			second = second->next;
		}
		stack_a = stack_a->next;
	}
	return 0;
}

int	num_arg(char *s)
{
	int i;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return 1;
		i++;
	}
	return 0;
}

