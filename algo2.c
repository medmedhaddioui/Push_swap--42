/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/05 19:21:48 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	get_index(int nb, t_list *stack_a)
// {
// 	int	index;

// 	index = 0;
// 	while (stack_a)
// 	{
// 		if (stack_a->content == nb)
// 			break ;
// 		stack_a = stack_a->next;
// 		index++;
// 	}
// 	return (index);
// }
int *ft_sort(int *arr,int len)
{
	int i;
	i = 0;
	int j;
	int tmp;
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
	return arr;
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
	arr = ft_sort(arr,len);
	return (arr);
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

void	sort_100(t_list **stack_a, t_list **stack_b, int c)
{
	int	*arr;
	int	index_arr;
	int	index_top;

	arr = ft_copy(*stack_a, c);
	index_top = 0;
	while (index_top < c)
	{
		index_arr = get_index(arr, c, (*stack_a)->content);
		if (index_arr == index_top)
		{
			pb(stack_a, stack_b);
			index_top++;
		}
		else
			ra(stack_a, 0);
	}
	while (index_top > 0)
	{
		pa(stack_a,stack_b);
		index_top--;
	}
}
