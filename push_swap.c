/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:29 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/18 15:06:55 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack_a)
{
	ft_lstclear(stack_a);
	ft_exit();
}

int	sort_check(t_list *stack_a)
{
	t_list	*second;

	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content > second->content)
				return (0);
			second = second->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_size(t_list **stack_a, t_list **stack_b)
{
	int	c;

	c = ft_lstsize(*stack_a);
	if (sort_check(*stack_a))
		return ;
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
	if (c > 100)
		sort_500(stack_a, stack_b, c);
}

t_list	*put(char **arr, t_list **stack_a)
{
	t_list	*node;
	int		j;

	j = 0;
	if (!arr[j])
		free_stack_arr(stack_a, arr);
	while (arr[j])
	{
		if (num_arg(arr[j]))
			free_stack_arr(stack_a, arr);
		j++;
	}
	while (j > 0)
	{
		node = ft_lstnew(ft_atoi(arr[--j], stack_a, arr));
		if (!node)
			free_stack_arr(stack_a, arr);
		ft_lstadd_front(stack_a, node);
	}
	return (*stack_a);
}

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
	if (!dup_check(stack_a))
		free_stack(&stack_a);
	sort_size(&stack_a, &stack_b);

	ft_lstclear(&stack_a);
	return (0);
}
