/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/12 19:06:42 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>


typedef struct s_node
{
    int val_a;
    int val_b;
    int cost_a;
    int cost_b;
    int cost_ab;
    int move_a;
    int move_b;
    int operation;
}              t_node;

void display_a(t_stack *a)
{
    printf("stack a:\n");
    while(a)
    {
        printf("%d ", a->data);
        a = a->next;
    }
        printf("\n");

}

void display_b(t_stack *b)
{
    printf("stack b:\n");

    while(b)
    {
        printf("%d ", b->data);
        b = b->next;
    }
        printf("\n");
}

int min_stack_a(t_stack *a)
{
    if(!(a))
        return (-1);
    int min = a->data;
    while(a)
    {
        if(min > a->data)
            min = a->data;
        a = a -> next;
    }
    return (min);
}

int get_max(t_stack *a, int val)
{
    int res;
    t_stack *tmp;
    t_stack *r;
    
    r = a;
    tmp = NULL;
    while(a)
    {
        if(a->data > val)
        {
            t_stack *new = ft_lstnew(a->data);
            ft_lstadd_front(&tmp, new);
        }
        a = a -> next;
    }
    res = min_stack_a(tmp);
    if(res < val)
        res = min_stack_a(r);
    ft_lstclear(&tmp);
    return (res);
}

int get_index_of_node(t_stack *s, int val)
{
    int i;

    if(!s)
        return (-1);
    i = 0;
    while(s)
    {
        if(s->data == val)
            return (i);
        i++;
        s =s ->next;
    }
    return (-1);
}

int move_node(t_stack *s, int val)
{
    int size;
    int index;
    
    if(!s)
        return (-1);
    size = ft_lstsize(s);
    index = get_index_of_node(s, val);
    if(index > size - index)
        return (1);
    return (0);
}

int get_cost(t_stack *s, int val)
{
    int size;
    int index;
    
    if(!s)
        return (-1);
    size = ft_lstsize(s);
    index = get_index_of_node(s, val);
    if(index > size - index)
    // puts("rra\n");
        return (size - index);
    // puts("ra\n");
    return (index);
}

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

t_node best_move(t_stack *a, t_stack *b, int val_b)
{
    t_node node;
    node.val_b = val_b;
    node.val_a = get_max(a, node.val_b);
    node.cost_a = get_cost(a, node.val_a);
    node.cost_b = get_cost(b, node.val_b);
    
    if(node.cost_a == 0)
        node.move_a = 2;
    else
        node.move_a = move_node(a, node.val_a);
    
    if(node.cost_b == 0)
        node.move_b = 2;
    else
        node.move_b = move_node(b, node.val_b);
    node.operation = set_operation(node.move_a, node.move_b);
    if(node.move_a == node.move_b)
    {
        if(node.cost_a  > node.cost_b)
            node.cost_ab = node.cost_a + 1;
        else    
            node.cost_ab = node.cost_b + 1;
    }
    else 
        node.cost_ab = node.cost_a + node.cost_b + 1;
    return (node);
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void sa(t_stack **a, int vlag)
{
    int size;

    size = ft_lstsize(*a);
    if(size <= 1)
        return ;
    swap(&(*a) ->data, &(*a)->next->data);
    if(vlag == 1)
        ft_putstr("sa\n");
}
void sb(t_stack **b, int vlag)
{
    int size;

    size = ft_lstsize(*b);
    if(size <= 1)
        return ;
    swap(&(*b) ->data, &(*b)->next->data);
    if(vlag == 1)
        ft_putstr("sb\n");
}
void ss(t_stack **a, t_stack **b)
{
    sa(a, 0);
    sa(b, 0);
    ft_putstr("ss\n");
}
void pb(t_stack **a, t_stack **b)
{
    if(!(*a))
        return ;
    t_stack * new;
    
    new = ft_lstnew((*a)->data);
    if(!new)
        return ;
    ft_lstadd_front(b, new);
    ft_lstdel_front(a);
    ft_putstr("pb\n");
}
void pa(t_stack **a, t_stack **b)
{
    if(!(*b))
        return ;
    t_stack *new;
    
    new = ft_lstnew((*b)->data);
    if(!new) 
        return ;
    ft_lstadd_front(a, new);
    ft_lstdel_front(b);
    ft_putstr("pa\n");
}
void ra(t_stack **a, int i)
{
    t_stack *first_elem;
    t_stack *last_elem;
    
    if(!(*a))
        return ;
    first_elem = *a;
    last_elem = ft_lstlast(*a);
    (*a) = (*a)->next;
    last_elem->next = first_elem;
    first_elem->next = NULL;
    if (i == 1)
        ft_putstr("ra\n");
}
void rb(t_stack **b, int vlag)
{
    t_stack *first_elem;
    t_stack *last_elem;
    
    if(!(*b))
        return ;
    first_elem = *b;
    last_elem = ft_lstlast(*b);
    (*b) = (*b)->next;
    last_elem->next = first_elem;
    first_elem->next = NULL; 
    if(vlag == 1)
        ft_putstr("rb\n");
}
void rr(t_stack **a, t_stack **b)
{
    ra(a, 0);
    rb(b, 0);
    ft_putstr("rr\n");
}
void rra(t_stack **a, int vlag)
{
    t_stack *last;
    t_stack *before_last;
    
    if(!(*a))
        return ;
    last = ft_lstlast(*a);
    before_last = ft_lst_before_last(*a);
    last->next = *a;
    *a = last;
    before_last->next = NULL;
    if(vlag == 1)
        ft_putstr("rra\n");
}
void rrb(t_stack **b, int vlag)
{
    t_stack *last;
    t_stack *before_last;
    
    if(!(*b))
        return ;
    last = ft_lstlast(*b);
    before_last = ft_lst_before_last(*b);
    last->next = *b;
    *b = last;
    before_last->next = NULL;
    if(vlag == 1)
        ft_putstr("rrb\n");
}
void rrr(t_stack **a, t_stack **b)
{
    rra(a, 0);
    rrb(b, 0);
    ft_putstr("rrr\n");
}

void opeartion1_a(t_stack **a,t_node node)
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

void opeartion1_b(t_stack **b,t_node node)
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

void operation2(t_stack **a, t_stack **b, t_node node)
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

void get_operation(t_stack **a, t_stack **b, t_node node)
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
void sort_three(t_stack **a)
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

t_node choose_best_move_2(t_stack *a, t_stack *b)
{
    t_stack *tmp= b;
    t_node node = best_move(a, b, tmp->data);
    while(tmp)
    {
        t_node node1 = best_move(a, b, tmp->data);
        if(node.cost_ab > node1.cost_ab)
            node =node1;
        tmp = tmp->next;
    }
    return node;
}

void final_case(t_stack **a, t_stack **b)
{
    t_stack *tmp = *b;
    int size = ft_lstsize(tmp);
    t_node node;
    int i = -1;
    while(++i < size)
    {
        node =choose_best_move_2(*a, *b);
        get_operation(a, b, node);
        pa(a, b);
        // printf("tmp ->data   : %d\n",node.val_b);

        // tmp = tmp ->next;
    }
}

void bubble_sort(int *t, int n) 
{
    int i = 0;
    int j;
    int tmp;
    while (i < n)
    {
        j = i +1;
        while(j < n)
        {
            if (t[i] > t[j])
            {
                tmp = t[i];  
                t[i] = t[j];  
                t[j] = tmp;
            }
            j++;
        }
        i++;
    }
} 

int get_median(t_stack *stack)
{
    int size = ft_lstsize(stack);
    int *t = malloc(sizeof(int) * size);
    if(!t)
       return (-1);

    int i = -1;
    while(++i < size)
    {
        t[i] = stack->data;
        stack = stack->next;
    }

    bubble_sort(t, size);
    // i = 0;
    // while(i < size)
    // {
    //     printf("%d ",t[i]);
    //     i++;
    // }
        // printf("\n");
    int median = -1;
    int index_median = (size / 2);
    median = t[index_median];
        // printf("median %d\n", median);
    free(t);
    return (median);
            
}

int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    int i = 0;
    
    a = NULL;
    b = NULL;
    if(ac == 1 || !strcmp(av[1], " "))
        return (0);
    while(++i < ac)
    {
        t_stack *new = ft_lstnew(ft_atoi(av[i]));
        // ft_parsing(av[i], ' ');
        ft_lstadd_back(&a, new);
    }
    int size = ft_lstsize(a);
    int median = get_median(a);
    int j = -1;
        while(++j < size - 3)
        {
            
                pb(&a, &b);
                if(ft_lstsize(b) >= 2)
                {
                    if( b->data < median)
                        rb(&b, 1);
                }                
        }
    sort_three(&a);
    final_case(&a, &b);
    int min_a = min_stack_a(a);
    // printf("%d", min_a);
    int index = get_index_of_node(a, min_a);
    // printf("index = %d\n", index);
    // if(index == size - index)
    // {
    //     while(a->data != min_a)
    //         ra(&a, 1);
    // }
    // else 
    if(index > size - index)
    {
        while(a->data != min_a)
            rra(&a, 1);      
    }
    else
    {
        while(a->data != min_a)
        ra(&a, 1);
    }
    // display_a(a);
    
    return (0);
}