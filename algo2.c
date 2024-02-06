/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/06 23:28:03 by mel-hadd         ###   ########.fr       */
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
	while (stack_a)
	{
		arr[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	arr = ft_sort(arr, len);
	return (arr);
}
int	get_index(int *arr, int len, int nb)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (nb == arr[i])
		{
			// break ;
			return (i);
		}
		i++;
	}
	return (i);
}

void	sort_100(t_list **stack_a, t_list **stack_b, int c, int re)
{
	int		*arr;
	int		index_arr;
	int		t;
	int		g;
	t_list	*head;

	arr = ft_copy(*stack_a, c);
	t = 0;
	g = c;
	head = NULL;
	while (t < g)
	{
		re = 10;
		head = *stack_a;
		index_arr = get_index(arr, c, head->content);
		if (index_arr < t)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 0);
			t++;
		}
		else if (index_arr <= t + re)
		{
			pb(stack_a, stack_b);
			t++;
		}
		else
			ra(stack_a, 0);
	}
}
