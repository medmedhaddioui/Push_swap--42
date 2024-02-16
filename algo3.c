#include "push_swap.h"

int push_check_500(int index_arr,int index, t_list **stack_a,t_list **stack_b)
{
	int re;
    re = 35;
	if (index_arr < index)
	{
			pb(stack_a, stack_b);
			rb(stack_b, 0);
			index++;
	}
	else if (index_arr <= index + re)
	{
			pb(stack_a, stack_b);
			index++;
	}
	else
		ra(stack_a, 0); 
	return index;
}

void	sort_500(t_list **stack_a, t_list **stack_b, int c)
{
	int	*arr;
	int	index_arr;
	int	index;

	arr = ft_copy(*stack_a, c);
	if (!arr)
	{
		free(arr);
		exit(1);
	}
	index = 0;
	while (index < c)
    {
		index_arr = get_index(arr, c, (*stack_a)->content);
		index = push_check_500(index_arr,index,stack_a,stack_b);
	}
	free(arr);
	back_a(stack_a, stack_b, c);
}