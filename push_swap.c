/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:29 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/04 16:08:17 by mel-hadd         ###   ########.fr       */
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
	printf("---stack_a---\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("---stack_b---\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	return (0);
}

t_list	*put(char **arr, t_list **stack_a)
{
	t_list	*node;
	int		j;

	j = 0;
	while (arr[j])
		num_arg(arr[j++]);
	while (j > 0)
	{
		node = ft_lstnew(ft_atoi(arr[--j]));
		if (!node)
			ft_lstclear(&node, del);
		ft_lstadd_front(&(*stack_a), node);
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
		sort_5(stack_a,stack_b,c);
	if (c > 5 && c <= 100)
		sort_100(stack_a,stack_b,c);
}
