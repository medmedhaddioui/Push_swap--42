/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:25:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/14 15:30:39 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker_bonus.h"



void instruct_cmp (char *str, t_list *stack_a, t_list *stack_a)
{
	
}
void ft_read_inst(t_list *stack_a, t_list *stack_b)
{
	char *str;
	str = get_next_line(0);
	while (str)
	{
		instruct_cmp(str, stack_a, stack_b);
		printf("%s\n", str); // Print the string here
		str = get_next_line(0);
	}
}

t_list	*put(char **arr, t_list **stack_a)
{
	t_list	*node;
	int		j;

	j = 0;
	if (!arr[j])
		free_stack_arr(stack_a,arr);
	while (arr[j])
	{
		if (num_arg(arr[j]))
			free_stack_arr(stack_a,arr);
		j++;
	}
	while (j > 0)
	{
		node = ft_lstnew(ft_atoi(arr[--j], stack_a , arr));
		if (!node)
			free_stack_arr(stack_a,arr);
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
	ft_lstclear(&stack_a);
	return (0);
}