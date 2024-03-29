/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:20 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/02/22 18:51:50 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
long long			ft_atoi( char *nptr, t_list **stack_a, char **arr);
void				sa(t_list **stack_a, int i);
void				sb(t_list **stack_b, int i);
void				ss(t_list **stack_a, t_list **stack_b, int i);
void				ra(t_list **stack_a, int i);
void				rb(t_list **stack_b, int i);
void				rr(t_list **stack_a, t_list **stack_b, int i);
void				rra(t_list **stack_a, int i);
void				rrb(t_list **stack_a, int i);
void				rrr(t_list **stack_a, t_list **stack_b, int i);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ft_exit(void);
void				ft_free(char **arr);
void				ft_putstr(char *s);
int					num_arg(char *av);
int					dup_check(t_list *stack_a);
int					sort_check(t_list *stack_a);
char				**ft_split(char const *s, char c);
t_list				*put(char **arr, t_list **stack_a);
void				ft_lstclear(t_list **lst);
void				sort_size(t_list **stack_a, t_list **stack_b);
void				sort_2(t_list **stack_a);
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack_a, t_list **stack_b, int c);
void				sort_5(t_list **stack_a, t_list **stack_b, int c);
void				sort_100(t_list **stack_a, t_list **stack_b, int c);
void				sort_500(t_list **stack_a, t_list **stack_b, int c);
int					min(t_list *s);
int					check_len(char *str);
int					*ft_copy(t_list *stack_a, int len);
int					get_index(int *arr, int len, int nb);
int					*ft_sort(int *arr, int len);
void				back_a(t_list **stack_a, t_list **stack_b, int c);
int					get_max(t_list *s);
int					get_index_b(t_list *stack_b, int nb);
void				free_stack_arr(t_list **stack_a, char **arr);
void				free_stack(t_list **stack_a);
int					push_check_500(int index_arr, int index, t_list **stack_a,
						t_list **stack_b);
int					push_check_100(int index_arr, int index, t_list **stack_a,
						t_list **stack_b);

#endif
