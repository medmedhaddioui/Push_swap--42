/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd 2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:26 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/01/20 15:46:30 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd2(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr_fd2("(null)", 1));
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
