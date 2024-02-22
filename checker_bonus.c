/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:25:21 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/22 17:27:57 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	instruct_cmp(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(stack_a, 2);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(stack_b, 2);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stack_a, stack_b, 2);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(stack_a, 2);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(stack_b, 2);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(stack_a, stack_b, 2);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(stack_a, 2);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(stack_b, 2);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(stack_a, stack_b, 2);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	ft_check_sorted(int *arr, t_list *stack_a, t_list *stack_b, int len)
{
	int	i;

	i = 0;
	if (stack_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (i < len)
	{
		if (arr[i] == stack_a->content)
		{
			i++;
			stack_a = stack_a->next;
		}
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

void	ft_read_inst(t_list **stack_a, t_list **stack_b)
{
	int		*arr;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if ((instruct_cmp(str, stack_a, stack_b)) == 0)
		{
			get_next_line(-1);
			free_stacks(stack_a, stack_b);
			free(str);
			ft_exit();
		}
		free(str);
		str = get_next_line(0);
	}
	arr = ft_copy(*stack_a, ft_lstsize(*stack_a));
	ft_check_sorted(arr, *stack_a, *stack_b, ft_lstsize(*stack_a));
	free(arr);
	free_stacks(stack_a, stack_b);
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
	{
		ft_lstclear(&stack_a);
		ft_exit();
	}
	ft_read_inst(&stack_a, &stack_b);
	return (0);
}
