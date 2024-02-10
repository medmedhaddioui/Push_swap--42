/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:29 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/10 15:47:46 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**arr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arr = NULL;
	if (ac == 1)
		exit(0);
	i = ac - 1;
	while (i)
	{
		arr = ft_split(av[i], ' ');
		stack_a = put(arr, &stack_a);
		ft_free(arr);
		i--;
	}
	dup_arg(stack_a);
	sort_size(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}

t_list	*put(char **arr, t_list **stack_a)
{
	t_list	*node;
	int		j;

	j = 0;
	while (arr[j])
	{
		if (num_arg(arr[j]))
		{
			ft_free(arr);
			ft_exit();
		}
		j++;
	}
	while (j > 0)
	{
		node = ft_lstnew(ft_atoi(arr[--j]));
		if (!node)
		{
			free(node);
			ft_lstclear(stack_a);
			ft_exit();
		}
		ft_lstadd_front(stack_a, node);
	}
	return (*stack_a);
}

void	sort_size(t_list **stack_a, t_list **stack_b)
{
	int	c;

	c = ft_lstsize(*stack_a);
	if (c == 2)
		sort_2(stack_a);
	if (c == 3)
		sort_3(stack_a);
	if (c == 4)
		sort_4(stack_a, stack_b, c);
	if (c == 5)
		sort_5(stack_a, stack_b, c);
	if (c > 5 && c <= 100)
		sort_100(stack_a, stack_b, c);
	if (c > 100 && c <= 500)
		sort_500(stack_a, stack_b, c);
}
