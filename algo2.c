/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/05 18:35:39 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	get_index(int nb, t_list *stack_a)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->content == nb)
			break;
		stack_a = stack_a->next;
		index++;
	}
	return (index);
}
int *ft_copy(t_list *stack_a, int len)
{
	int *arr;
	int i;
	i = 0;
	int j;
	arr = malloc(sizeof(int)* len);
	while (stack_a)
	{
		
		arr[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				int tmp;
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
int get_i(int *arr, int len, int nb)
{
	int i;
	i = 0;
	while (i < len)
	{
		if (nb == arr[i])
			break;
		i++;
	}
	return i;	
}
void ft_display(t_list *stack_a)
{
	while(stack_a)
	{
		printf("%d\n" ,stack_a->content);
		stack_a = stack_a->next;
	}
}
void	sort_100(t_list **stack_a, t_list **stack_b, int c)
{
	int *arr;
	arr = ft_copy(*stack_a, c);
	int index_arr;
	// int index_a;
	int i = 0;
	while (i < c)
	{
		
		index_arr = get_i(arr,c,(*stack_a)->content);
		if (index_arr <= i)
	{
			pb(stack_a,stack_b);
		
		i++;
	}
		else
			ra(stack_a,0);
	}
	ft_display(*stack_b);
	exit(0);

}
