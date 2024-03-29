/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:37 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/22 18:48:54 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_list *s)
{
	int	min;

	min = s->content;
	while (s)
	{
		if (s->content < min)
			min = s->content;
		s = s->next;
	}
	return (min);
}

int	get_max(t_list *s)
{
	int	max;

	max = s->content;
	while (s)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

int	get_index(int *arr, int len, int nb)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (nb == arr[i])
			break ;
		i++;
	}
	return (i);
}

int	get_index_b(t_list *stack_b, int nb)
{
	int	index;

	index = 0;
	while (stack_b)
	{
		if (stack_b->content == nb)
			break ;
		index++;
		stack_b = stack_b->next;
	}
	return (index);
}

int	check_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		len++;
		i++;
	}
	while (str[i] == '0')
		i++;
	i--;
	while (str[len])
		len++;
	len -= i;
	if (len > 12)
		return (0);
	return (1);
}
