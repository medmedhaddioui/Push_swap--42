#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**arr;
	t_list	*stack_a;

	stack_a = NULL;
	arr = NULL;
	i = ac - 1;
	while (i)
	{
		arr = ft_split(av[i], ' ');
		stack_a = put(arr, &stack_a);
		i--;
	}
	dup_arg(stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
t_list	*put(char **arr, t_list **stack_a)
{
	t_list	*node;
	int		j;

	j = 0;
	while (arr[j])
		parsing(arr[j++]);
	while (j > 0)
	{
		node = ft_lstnew(ft_atoi(arr[--j]));
		ft_lstadd_front(&(*stack_a), node);
	}
	return *stack_a;
}
