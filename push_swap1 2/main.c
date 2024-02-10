/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/10 01:42:57 by aben-cha         ###   ########.fr       */
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
        printf("   %d\n", a->data);
        a = a->next;
    }
}
void display_b(t_stack *b)
{
    printf("stack b:\n");

    while(b)
    {
        printf("   %d\n", b->data);
        b = b->next;
    }
}

int min_stack_a(t_stack *a)
{
    t_stack *tmp;
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
void sa(t_stack **a)
{
    int size;

    size = ft_lstsize(*a);
    if(size <= 1)
        return ;
    swap(&(*a) ->data, &(*a)->next->data);
    ft_putstr("sa\n");
}
void sb(t_stack **b)
{
    int size;

    size = ft_lstsize(*b);
    if(size <= 1)
        return ;
    swap(&(*b) ->data, &(*b)->next->data);
    ft_putstr("sb\n");
}
void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sa(b);
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
void ra(t_stack **a)
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
    ft_putstr("ra\n");
}
void rb(t_stack **b)
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
    ft_putstr("rb\n");
}
void rr(t_stack **a, t_stack **b)
{
    ra(a);
    ra(b);
    ft_putstr("rr\n");
}
void rra(t_stack **a)
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
    ft_putstr("rra\n");
}
void rrb(t_stack **b)
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
    ft_putstr("rrb\n");
}
void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    ft_putstr("rrr\n");
}

// t_node choose_best_move(t_stack *a, t_stack *b)
// {
//     t_stack *tmp= b;
//     t_node node = best_move(a, b, tmp->data);
    
//     tmp = tmp->next;
//     while(tmp)
//     {
//         t_node node1 = best_move(a, b, tmp->data);

//         if(node.cost_ab > node1.cost_ab)
//             node =node1;
//         tmp = tmp->next;
//     }
//     return node;
// }




void opeartion1_a(t_stack **a,t_node node)
{
    if(!(*a))
        return ;
    int size = ft_lstsize(*a);
    int index = get_index_of_node(*a, node.val_a);

    if(node.move_a == 0) // ra
    {
        while(index--)
            ra(a);
    }
    else if(node.move_a == 1) // rra
    {
        size = size - index;
        while(size--)
            rra(a);
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
            rb(b);
    }
    else if(node.move_b == 1) // rra
    {
        size = size - index;
        while(size--)
            rrb(b);
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
        // printf("test1\n");

            while(i_a--)
                rr(a,b);
        }
        else if(i_a > i_b)
        {
            int c = i_a - i_b;
            while(i_b--)
                rr(a, b);
            while(c--)
                ra(a);
        }
        else if(i_a < i_b)
        {
            int c = i_b -i_a;
            while(i_a--)
                rr(a, b);
            while(c--)
                rb(b);
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
                rra(a);
        }
        else if(i_a < i_b)
        {

            int c = i_b -i_a;
            while(i_a--)
                rrr(a, b);
            while(c--)
                rrb(b);
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
        operation2(a, b, node);
    // pa(a, b);
}
void sort_three(t_stack **a)
{
    if(!(*a))
        return ;
    t_stack *one = *a;
    t_stack *two = one->next;
    t_stack *third = two->next;
        
    if((one->data > two->data) && (one->data < third->data))
        sa(a);
    else if((one->data > two->data) && (one->data > third->data) && (two->data > third->data))
    {
        sa(a);
        rra(a);
    }
    else if((one->data > two->data) && (one->data > third->data) && (two->data < third->data))
        ra(a);
    else if ((one->data < two->data) && (one->data < third->data) && (two->data > third->data))
    {
        sa(a);
        ra(a);
    }
    else if((one->data < two->data) && (one->data > third->data) && (two->data > third->data))
        rra(a);
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
        // printf("-----------------------\n");
        // printf("val_a   : %d\n",node1.val_a);
        // printf("val_b   : %d\n",node1.val_b);
        // printf("cost_a  : %d\n",node1.cost_a);
        // printf("cost_b  : %d\n",node1.cost_b);
        // printf("cost_ab : %d\n",node1.cost_ab);
        // printf("move_a  : %d\n",node1.move_a);
        // printf("move_b  : %d\n",node1.move_b);
        // printf("operation  : %d\n",node1.operation);
        // printf("-----------------------\n");
        tmp = tmp->next;
    }


    return node;
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
    
    int j = -1;
        while(++j < size - 3)
            pb(&a, &b);
    sort_three(&a);
    // display_a(a);
    // display_b(b);   
    t_stack *tmp = b;
    t_node node;
    i= 0;
    while(tmp)
    {
        node = choose_best_move_2(a, b);
        get_operation(&a, &b, node);
        // display_b(b);

        // i++;
        // printf("val_b :%d, val_a :%d\n", node.val_b, node.val_a);
        pa(&a, &b);
        // display_a(a);
        // display_b(b);
        // printf("tmp->data : %d\n",tmp->data);
        tmp = tmp->next;
                
    }

    t_stack *tmp1 = b;
    t_node node1;
    i= 0;
    while(tmp1)
    {
        node1 = choose_best_move_2(a, b);
        get_operation(&a, &b, node1);
        // display_b(b);

        // printf("val_b :%d, val_a :%d\n", node1.val_b, node1.val_a);
        pa(&a, &b);
        // display_a(a);
        // display_b(b);
        // printf("tmp1->data : %d\n",tmp1->data);
        tmp1 = tmp1->next;
                
    }

    int min_a = min_stack_a(a);
    int index = get_index_of_node(a, min_a);
    if(index > size - index)
    {
        int c = size - index;
        while(c--)
            rra(&a);
                
    }
    else
    while(index--)
        ra(&a);

    display_a(a);
    // display_b(b);   

    return (0);
}

