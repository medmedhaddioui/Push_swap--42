/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:24:49 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/05 17:34:25 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	get_index(t_list *stack_a)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->content == min(stack_a)) 
			break ;
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

void	sort_100(t_list **stack_a, t_list **stack_b, int c)
{
	int *arr = malloc(sizeof(int) * c);
	arr = ft_copy(*stack_a, c);
	int index_a;
	index_a = get_index(*stack_a);
	printf("%d\n",index_a);
	(void)stack_b;
}
