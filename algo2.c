/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/10 19:17:34 by mel-hadd         ###   ########.fr       */
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
			while (index_b != 0)
			{
				rb(stack_b, 0);
				index_b--;
			}
		}
		else if (index_b > half)
		{
			while (index_b != size)
			{
				rrb(stack_b, 0);
				index_b++;
			}
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
	int	re;

	re = 15;
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
	}
	free(arr);
	back_a(stack_a, stack_b, c);
}

void	sort_500(t_list **stack_a, t_list **stack_b, int c)
{
	int	*arr;
	int	index_arr;
	int	index;
	int	re;

	arr = ft_copy(*stack_a, c);
	if (!arr)
	{
		free(arr);
		exit(1);
	}
	index = 0;
	while (index < c)
	{
		re = 30;
		index_arr = get_index(arr, c, (*stack_a)->content);
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
	}
	free(arr);
	back_a(stack_a, stack_b, c);
}
