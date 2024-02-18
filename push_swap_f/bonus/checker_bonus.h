/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:13:15 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/18 15:56:04 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//het_nexy_line
char	*get_next_line(int fd);
int	    ft_check(char *s, char c);
char	*ft_join_free(char *s, const char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char *s1, const char *s2);


typedef struct s_stack
{
	int data;
	struct s_stack	*next;
}		t_stack;

typedef struct s_best_move
{
    int val_a;
    int val_b;
    int cost_a;
    int cost_b;
    int cost_ab;
    int move_a;
    int move_b;
    int operation;
}              t_best_move;
//fn1--------------------------
t_stack *ft_lstnew(int data);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
//fn2--------------------------
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
t_stack *ft_lst_before_last(t_stack *lst);
void    ft_lstdel_front(t_stack **lst);
int     check_char(char *s);
//fn3--------------------------
void    ft_putstr(char *s, int i);
int spaces(char *s);
// size_t	ft_strlen(const char *s);
// char	*ft_strdup(const char *s);// check s== NULL
void    free_array(char **av);
void    free_data(char **res ,t_stack **stack, t_stack *new, int vlag);
//split---
int	    nbr_strings(const char *s, char c);
char	**ft_split(char const *s, char c);
//parsing
int     check_min_max(long result, int sign);
int     ft_atoi(const char *str);
int    case_one(char **res, char *av, int count_words, t_stack **stack);
int    case_two(char **res, char *av, t_stack **stack);
int    parsing(char *av, t_stack **stack, char c);

//fn4-----------------------------
int     is_double(t_stack *stack, int number);
void    swap(int *a, int *b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
//fn5----------
void    pb(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);

//fn6--------------------------
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
int     get_median(t_stack *stack);
void    bubble_sort(int *t, int n) ;

//fn7---------------------------
int min_stack_a(t_stack *a);
int get_max(t_stack *a, int val);
int get_index_of_node(t_stack *s, int val);
int get_move(t_stack *s, int val);
int get_cost(t_stack *s, int val);

//fn8------------------------------
int     set_operation(int move_a, int move_b);
void    get_operation(t_stack **a, t_stack **b, t_best_move node);
void    operation2_rr(t_stack **a, t_stack **b, int i_a, int  i_b);
void    operation2_rrr(t_stack **a, t_stack **b, int i_a, int  i_b);
void    operation2(t_stack **a, t_stack **b, t_best_move node);
//f9----------------------------------


void    sort_two(t_stack **a);
void    sort_three(t_stack **a);
void    opeartion1_a(t_stack **a, t_best_move node);
void    opeartion1_b(t_stack **b, t_best_move node);
int     set_cost_ab(int move_a, int move_b, int cost_a, int cost_b);

//f10--------------------------------------------------
int max_stack_a(t_stack *a);
t_best_move     set_best_move(t_stack *a, t_stack *b, int val_b);
t_best_move     get_best_move(t_stack *a, t_stack *b);
void            final_case(t_stack **a, t_stack **b);
void get_stack_a_sorted(t_stack **a, int size);

//f11-------------------
int	ft_strcmp(char *s1, char *s2);
int apply_instructions(t_stack **a,t_stack **b, char *s);
int is_sorted(t_stack *a);
int read_instructions(t_stack *a, t_stack *b);

#endif