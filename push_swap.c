#include "libft/libft.h"
#include "push_swap.h"

t_list	*put_me(int nb)
{
	t_list *new_node;
	new_node = malloc (sizeof(t_list));
	new_node->data = nb;
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		i;
	(void) av;
	i = 1;
	if (ac < 2)
		return (write(1, "Error\n", 6), 0);
	while (av[i])
	{
		put_me(ft_atoi(av[i]));
		i++;
	}
}
