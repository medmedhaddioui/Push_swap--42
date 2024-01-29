#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**tab;
	int		j;

	tab = NULL;
	stack_b = NULL;
	i = ac - 1;

	while (i)
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		while (tab[j])
			parsing(tab[j++]);
		while (j > 0)
		{
			node = ft_lstnew(ft_atoi(tab[--j]));
			ft_lstadd_front(&stack_a, node);
		}
		i--;
	} 
	printf(" stack_a \n");
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
