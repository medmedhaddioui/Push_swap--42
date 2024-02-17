/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/17 14:32:48 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*ft_copy(t_list *stack_a, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (stack_a)
	{
		arr[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	arr = ft_sort(arr, len);
	return (arr);
}

void	back_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	half;
	int	index_b;
	int	max;

	i = 0;
	while (size > i)
	{
		half = size / 2;
		max = get_max(*stack_b);
		index_b = get_index_b(*stack_b, max);
		if (index_b <= half)
		{
			while (index_b-- != 0)
				rb(stack_b, 0);
		}
		else if (index_b > half)
		{
			while (index_b++ != size)
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

void	sort_100(t_list **stack_a, t_list **stack_b, int c)
{
	int	*arr;
	int	index_arr;
	int	index;

	arr = ft_copy(*stack_a, c);
	if (!arr)
	{
		free(arr);
		exit(1);
	}
	index = 0;
	while (index < c)
	{
		index_arr = get_index(arr, c, (*stack_a)->content);
		index = push_check_100(index_arr, index, stack_a, stack_b);
	}
	free(arr);
	back_a(stack_a, stack_b, c);
}

int	push_check_100(int index_arr, int index, t_list **stack_a, t_list **stack_b)
{
	int	re;

	re = 15;
	if (index_arr < index)
	{
		pb(stack_a, stack_b);
		rb(stack_b, 0);
		index++;
	}
	else if (index_arr <= index + re)
	{
		pb(stack_a, stack_b);
		index++;
	}
	else
		ra(stack_a, 0);
	return (index);
}
