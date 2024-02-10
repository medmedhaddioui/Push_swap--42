/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:30:39 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/10 18:34:49 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long ft_atoi(const char *nptr, t_list **stack_a)
{
	int	sign;
	long long result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	result = result * sign;
	if (result >= INT_MAX)
	{
		ft_lstclear(stack_a);
		ft_exit();
	}
	return (result);
}

void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

void	ft_free(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

void	ft_free_stack_a(t_list *stack_a)
{
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}
