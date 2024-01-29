#include "push_swap.h"
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		sign *= -1;
		nptr ++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(0);
}
void ft_putstr(char *s)
{
	while (*s)
	{
		write(1,s,1);
		s++;
	}
}


