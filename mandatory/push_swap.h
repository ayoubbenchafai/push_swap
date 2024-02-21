/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:49:47 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/21 23:23:00 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;
typedef struct s_best_move
{
	int	val_a;
	int	val_b;
	int	cost_a;
	int	cost_b;
	int	cost_ab;
	int	move_a;
	int	move_b;
	int	operation;
}				t_best_move;
int			nbr_strings(const char *s, char c);
char		**ft_split(char const *s, char c);
t_stack		*ft_lstnew(int data);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst);
t_stack		*ft_lst_before_last(t_stack *lst);
void		ft_lstdel_front(t_stack **lst);
int			check_char(char *s);
long		ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
void		free_array(char **av);
void		free_data(char **res, t_stack **stack, t_stack *new, int vlag);
int			is_double(t_stack *stack, int number);
void		swap(int *a, int *b);
void		sa(t_stack **a, int vlag);
void		sb(t_stack **b, int vlag);
void		ss(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		ra(t_stack **a, int vlag);
void		rb(t_stack **b, int vlag);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a, int vlag);
void		rrb(t_stack **b, int vlag);
void		rrr(t_stack **a, t_stack **b);
void		bubble_sort(int *t, int n);
int			get_median(t_stack *stack);
int			min_stack_a(t_stack *a);
int			get_index_of_node(t_stack *s, int val);
int			get_move(t_stack *s, int val);
int			get_cost(t_stack *s, int val);
int			set_operation(int move_a, int move_b);
void		get_operation(t_stack **a, t_stack **b, t_best_move node);
void		operation2_rr(t_stack **a, t_stack **b, int i_a, int i_b);
void		operation2_rrr(t_stack **a, t_stack **b, int i_a, int i_b);
void		operation2(t_stack **a, t_stack **b, t_best_move node);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		opeartion1_a(t_stack **a, t_best_move node);
void		opeartion1_b(t_stack **b, t_best_move node);
int			set_cost_ab(int move_a, int move_b, int cost_a, int cost_b);
int			max_stack_a(t_stack *a);
t_best_move	set_best_move(t_stack *a, t_stack *b, int val_b);
t_best_move	get_best_move(t_stack *a, t_stack *b);
void		final_case(t_stack **a, t_stack **b);
void		get_stack_a_sorted(t_stack **a, int size);
int			check_min_max(long result, int sign);
t_stack		*get_greater_values(t_stack *a, int val);
int			find_min_greater_than(t_stack *a, int val);
int			parsing(char *av, t_stack **stack, char c);
int			is_sorted(t_stack *a);
void		sort_data(t_stack **a, t_stack **b, int size, int median);
int			check_errors(char **res, t_stack **stack, t_stack *new, int i);

#endif
