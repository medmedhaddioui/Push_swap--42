#include "push_swap.h"
void parsing(char *av)
{
	num_arg(av);
	dup_arg(av);
}
void	num_arg(char *av)
{
	int i;
	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (!(av[i] >= '0' && av[i] <= '9'))
			ft_exit();
		i++;
	}
}
void dup_arg ()

