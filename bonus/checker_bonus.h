/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:13:15 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/21 23:24:47 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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

char	*get_next_line(int fd);
int		ft_check(char *s, char c);
char	*ft_join_free(char *s, const char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char *s1, const char *s2);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lst_before_last(t_stack *lst);
void	ft_lstdel_front(t_stack **lst);
int		check_char(char *s);
long	ft_atoi(const char *str);
void	free_array(char **av);
void	free_data(char **res, t_stack **stack, t_stack *new, int vlag);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		nbr_strings(const char *s, char c);
char	**ft_split(char const *s, char c);
int		is_double(t_stack *stack, int number);
void	swap(int *a, int *b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
int		ft_strcmp(char *s1, char *s2);
int		apply_instructions(t_stack **a, t_stack **b, char *s);
int		is_sorted(t_stack *a);
int		read_instructions(t_stack *a, t_stack *b);
int		check_min_max(long result, int sign);
int		parsing(char *av, t_stack **stack, char c);
int		check_errors(char **res, t_stack **stack, t_stack *new, int i);

#endif
