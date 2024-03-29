/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:58:26 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/17 14:33:15 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"

int		instruct_cmp(char *str, t_list **stack_a, t_list **stack_b);
void	ft_check_sorted(int *arr, t_list *stack_a, t_list *stack_b, int len);
void	ft_read_inst(t_list **stack_a, t_list **stack_b);
t_list	*put(char **arr, t_list **stack_a);
void	free_stacks(t_list **stack_a, t_list **stack_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif
