/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:49:47 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/14 00:10:52 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // delete it
# include <limits.h>

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
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);// check s== NULL
void    free_array(char **av);
void    free_data(char **res ,t_stack **stack, t_stack *new, int vlag);
//split---
int	    nbr_strings(const char *s, char c);
char	**ft_split(char const *s, char c);
//parsing
int     check_min_max(long result, int sign);
int     ft_atoi(const char *str);
void    case_one(char **res, char *av, int count_words, t_stack **stack);
void    case_two(char **res, char *av, t_stack **stack);
void    parsing(char *av, t_stack **stack, char c);

//fn4-----------------------------
int     is_double(t_stack *stack, int number);
void    swap(int *a, int *b);
void    sa(t_stack **a, int vlag);
void    sb(t_stack **b, int vlag);
void    ss(t_stack **a, t_stack **b);
//fn5----------
void    pb(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    ra(t_stack **a, int i);
void    rb(t_stack **b, int vlag);
void    rr(t_stack **a, t_stack **b);

//fn6--------------------------
void    rra(t_stack **a, int vlag);
void    rrb(t_stack **b, int vlag);
void    rrr(t_stack **a, t_stack **b);
int     get_median(t_stack *stack);
void    bubble_sort(int *t, int n) ;

//fn7---------------------------
int min_stack_a(t_stack *a);
int get_max(t_stack *a, int val);
int get_index_of_node(t_stack *s, int val);
int get_move(t_stack *s, int val);
int get_cost(t_stack *s, int val);
// had chi mzl 
//fn8------------------------------
int set_operation(int move_a, int move_b);
void opeartion1_a(t_stack **a, t_best_move node);
void opeartion1_b(t_stack **b, t_best_move node);
void operation2(t_stack **a, t_stack **b, t_best_move node);
void get_operation(t_stack **a, t_stack **b, t_best_move node);

int set_operation(int move_a, int move_b)
{
    if(move_a != move_b)
        return (0);// different r or rr (a or b)
    else
    {
        if (move_a == 0)
            return (1);// means move each one of the top using r.
        else 
            return (2);// means move each one of the top using rr
    }
}
void opeartion1_a(t_stack **a, t_best_move node)
{
    if(!(*a))
        return ;
    int size = ft_lstsize(*a);
    int index = get_index_of_node(*a, node.val_a);

    if(node.move_a == 0) // ra
    {
        while(index--)
            ra(a,1);
    }
    else if(node.move_a == 1) // rra
    {
        size = size - index;
        while(size--)
            rra(a,1);
    }
    else
        return ;
}
void opeartion1_b(t_stack **b, t_best_move node)
{
    if(!(*b))
        return ;
    int size = ft_lstsize(*b);
    int index = get_index_of_node(*b, node.val_b);

    if(node.move_b == 0) // ra
    {
        while(index--)
            rb(b,1);
    }
    else if(node.move_b == 1) // rra
    {
        size = size - index;
        while(size--)
            rrb(b,1);
    }
    else
        return ;
}
void operation2(t_stack **a, t_stack **b, t_best_move node)
{

    if(node.operation == 1) //rr
    {
        int i_a = node.cost_a;
        int i_b = node.cost_b;
        
        if(i_a == i_b)
        {
            while(i_a--)
                rr(a,b);
        }
        else if(i_a > i_b)
        {
            int c = i_a - i_b;
            while(i_b--)
                rr(a, b);
            while(c--)
                ra(a,1);
        }
        else if(i_a < i_b)
        {
            int c = i_b -i_a;
            while(i_a--)
                rr(a, b);
            while(c--)
                rb(b,1);
        }
    }
    else if(node.operation == 2)
    {
        int i_a = node.cost_a;
        int i_b = node.cost_b;

        
        if(i_a == i_b)
        {
            while(i_a--)
                rrr(a,b);
        }
        else if(i_a > i_b)
        {
            int c = i_a - i_b;
            while(i_b--)
                rrr(a, b);
            while(c--)
                rra(a,1);
        }
        else if(i_a < i_b)
        {
            int c = i_b -i_a;
            while(i_a--)
                rrr(a, b);
            while(c--)
                rrb(b,1);
        }
    }
    else
        return ;
}
void get_operation(t_stack **a, t_stack **b, t_best_move node)
{
    if(node.operation == 0)
    {
        opeartion1_a(a, node);
        opeartion1_b(b, node);  
    }
    else
    {
        operation2(a, b, node);        
    }
}
//--------------------------------------------------

int             set_cost_ab(int move_a, int move_b, int cost_a, int cost_b)
{
    if(move_a == move_b)
    {
        if(cost_a  > cost_b)
            return (cost_a + 1);
        else    
            return (cost_b + 1);
    }
    else
        return (cost_a + cost_b + 1);
}

t_best_move     best_move(t_stack *a, t_stack *b, int val_b)
{
    t_best_move node;
    
    node.val_b = val_b;
    node.val_a = get_max(a, node.val_b);
    node.cost_a = get_cost(a, node.val_a);
    node.cost_b = get_cost(b, node.val_b);
    if(node.cost_a == 0)
        node.move_a = 2;
    else
        node.move_a = get_move(a, node.val_a);
    
    if(node.cost_b == 0)
        node.move_b = 2;
    else
        node.move_b = get_move(b, node.val_b);
    node.operation = set_operation(node.move_a, node.move_b);
    node.cost_ab = set_cost_ab(node.move_a, node.move_b, node.cost_a, node.cost_b);
    return (node);
}

void sort_two(t_stack **a)
{
    if(!(*a))
        return ;
    if(((*a)->data) > ((*a)->next->data))
            sa(a, 1);
    else    
        return ;
}
void s_3(t_stack **a)
{
    if(!(*a))
        return ;
    int max = max_stack_a(*a);

    if((*a)->data == max)
    {
        ra(a, 1);
        sort_two(a);
    }
    else if((*a)->next->data == max)
        rra(a, 1);
    else    
        sa(a, 1);
}
void            sort_three(t_stack **a)
{
    if(!(*a))
        return ;
    t_stack *one = *a;
    t_stack *two = one->next;
    t_stack *third = two->next;
        
    if((one->data > two->data) && (one->data < third->data))
        sa(a,1);
    else if((one->data > two->data) && (one->data > third->data) && (two->data > third->data))
    {
        sa(a,1);
        rra(a,1);
    }
    else if((one->data > two->data) && (one->data > third->data) && (two->data < third->data))
        ra(a,1);
    else if ((one->data < two->data) && (one->data < third->data) && (two->data > third->data))
    {
        sa(a,1);
        ra(a,1);
    }
    else if((one->data < two->data) && (one->data > third->data) && (two->data > third->data))
        rra(a,1);
}

t_best_move     get_best_move(t_stack *a, t_stack *b)
{
    t_stack *tmp;
    
    tmp = b;
    t_best_move node = best_move(a, b, tmp->data);
    while(tmp)
    {
        t_best_move node1 = best_move(a, b, tmp->data);
        if(node.cost_ab > node1.cost_ab)
            node =node1;
        tmp = tmp->next;
    }
    return node;
}

void            final_case(t_stack **a, t_stack **b)
{
    int size = ft_lstsize(*b);
    t_best_move node;
    int i = -1;
    while(++i < size)
    {
        node =get_best_move(*a, *b);
        get_operation(a, b, node);
        pa(a, b);
    }
}
#endif