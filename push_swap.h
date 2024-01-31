#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include  <string.h>

typedef struct s_list{
    int content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(int content);
int ft_lstsize(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_atoi(const char *nptr);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
void sa(t_list **stack_a, int i);
void sb(t_list **stack_b, int i);
void ss (t_list **stack_a, t_list **stack_b, int i);
void ra(t_list **stack_a, int i);
void rb(t_list **stack_b, int i);
void rr(t_list **stack_a, t_list **stack_b, int i);
void rra(t_list **stack_a, int i);
void rrb(t_list **stack_a, int i);
void rrr(t_list **stack_a,t_list ** stack_b, int i);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void	parsing(char *av);
void	ft_exit(void);
void ft_putstr(char *s);
void	num_arg(char *av);
void dup_arg (t_list *stack_a);
char	**ft_split(char const *s, char c);
t_list *put(char **arr,t_list** stack_a);








#endif
