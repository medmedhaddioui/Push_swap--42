#include "push_swap.h"
void parsing(char *av)
{
	num_arg(av);
}
void	num_arg(char *s)
{
	int i;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			ft_exit();
		i++;
	}
}
void dup_arg (t_list *stack_a)
{
	t_list *second;
	while (stack_a->next)
	{
		second = stack_a->next;
		while (second)
		{
			if (stack_a->content == second->content)
				ft_exit();
			second = second->next;
		}
		stack_a = stack_a->next;
	}
}

