#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	int		i;
	int		b;

	stack_b = NULL;
	tmp = stack_a;
	b = 0;
	i = 1;
	if (ac < 2)
		return (write(1, "Error\n", 6), 0);
	while (av[i])
	{
		node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_front(&stack_a, node);
		i++;
	}
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	pb(&stack_a, &stack_b);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
