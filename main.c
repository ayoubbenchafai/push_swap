/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:26:18 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/06 01:09:40 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_check_char(char *s)
{
    while(*s)
    {
        if(*s == '-' || *s == '+')
            s++;
        if(!(*s >= '0' && *s <= '9'))
            return (1);
        s++;
    }  
    return (0);
}
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
void free_array(char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}

static int ft_parsing(char *av, char c)
{
    int len_string;
    int n;
    char **res = NULL;
    len_string = nbr_strings(av, c);
    if (len_string > 1)
    {
        res = ft_split(av, c);
        int i = -1;
        while(++i < len_string)
        {
            if(ft_check_char(res[i]))
            {
                ft_putstr("Error\n");
                return (1);
            }
            n = ft_atoi(res[i]);
            printf("%d\n",n);
        }
        free_array(res);
    }
    else
    {
        res = ft_split(av, c);
        if(ft_check_char(res[0]))
        {
            ft_putstr("Error\n");
            return (1);
        }
        n = ft_atoi(res[0]);
        printf("%d\n", n);
        free_array(res);
    }
    return (0);
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
}
void sb(t_stack **b)
{
    int size;

    size = ft_lstsize(*b);
    if(size <= 1)
        return ;
    swap(&(*b) ->data, &(*b)->next->data);
}
void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sa(b);
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
}
void rr(t_stack **a, t_stack **b)
{
    ra(a);
    ra(b);
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
}
void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}
void sort(int *t, int size)
{
    int i = 1;
    int j = 0;
    int key = 0;
    int index;
    while(++i < size)
    {
        key = t[i];
        index = i;
        while(index > 0 && t[index - 1] > key)
        {
            t[index] = t[index -1];
            index = index - 1;
        }
        t[index] = key;   
    }
}


void sort_two(t_stack **a)
{
    if(!(*a))
        return ;
    if(((*a)->data) > ((*a)->next->data))
            sa(a);
    else    
        return ;
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

int max_stack_a(t_stack *a)
{
    if(!(a))
        return (-1);
    int max = a->data;
    while(a)
    {
        if(max < a->data)
            max = a->data;
        a = a-> next;
    }
    return (max);
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

int get_cost(t_stack *s, int val)
{
    int i;
    int c;
    int size;
    int index;
    
    if(!s)
        return (-1);
    i = -1;
    c = -1;
    size = ft_lstsize(s);
    index = get_index_of_node(s, val);
    if(index > size - index)
    // puts("rra\n");
        return (size - index);
    // puts("ra\n");
    return (index);
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
            // free(new);
        }
        a = a -> next;
    }
    res = min_stack_a(tmp);
    if(res < val)
        res = min_stack_a(r);
    return (res);
}


void move_number_to_top(t_stack *s, int option, int val_to_move)
{
    int index;
    int size;
    int i;
    
    if(!s)
        return ;// return -1
    i = -1;
    size = ft_lstsize(s);
    index = get_index_of_node(s, val_to_move);
    if(option == 0) // ra
    {
        int index = get_index_of_node(s, val_to_move);
        
    }
    else if(option == 1) //rra
    {
        
    }
    else
    {
        // do nothing 
        printf("do nothing \n");
    }
        
}
int move_node(t_stack *s, int val)
{
    int i;
    int c;
    int size;
    int index;
    
    if(!s)
        return (-1);
    i = -1;
    c = -1;
    size = ft_lstsize(s);
    index = get_index_of_node(s, val);
    if(index > size - index)
        return (1);
    return (0);
}

t_node best_move(t_stack *a, t_stack *b, int val_b)
{
    t_node node;
    node.val_b = val_b;
    node.val_a = get_max(a, node.val_b);
    node.cost_a = get_cost(a, node.val_a);
    node.cost_b = get_cost(b, node.val_b);
    // 0 : ra or 1 : rra
    if(node.cost_a == 0)
        node.move_a = 2;
    else
    node.move_a = move_node(a, node.val_a);
    
    if(node.cost_b == 0)
        node.move_b = 2;
    else
    node.move_b = move_node(b, node.val_b);
    if(node.move_a == node.move_b)
    {
        if(node.cost_a  > node.cost_b)
            node.cost_ab = node.cost_a + 1;
        else    
            node.cost_ab = node.cost_b + 1;
    }
    else 
        node.cost_ab = node.cost_a + node.cost_b + 1;
    // node->operation = 0 or 1 or 2;
    // return (node);
    return (node);
}

void insertion_sort(t_stack **a, t_stack **b)
{
    int size;
    
    if(!(*a))
        return ;
    size  = ft_lstsize(*a);
    if(size == 2)
        sort_two(a);
    if(size == 3)
        sort_three(a);
    else
    {
        int i = -1;
        // while(++i < size - 3)
        pb(a, b);
        pb(a, b);
        pb(a, b);
        t_stack *tmp = *b;
        while(tmp)
        {
            t_node node = best_move(*a, *b, tmp->data);

            printf("val_a : %d\n",node.val_a);
            printf("val_b : %d\n",node.val_b);
            printf("cost_a : %d\n",node.cost_a);
            printf("cost_b : %d\n",node.cost_b);
            printf("cost_ab : %d\n",node.cost_ab);
            printf("move_a : %d\n",node.move_a);
            printf("move_b : %d\n",node.move_b);
            printf("-----------------------\n");
            tmp = tmp->next;
        }
        // sort_three(a);
    }
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    int i = 0;
    if(ac == 1)
        return (0);
    while(++i < ac)
    {
        t_stack *new = ft_lstnew(ft_atoi(av[i]));
        // ft_parsing(av[i], ' ');
        ft_lstadd_back(&a, new);
    }
    insertion_sort(&a, &b);
    display_a(a);
    display_b(b);
    ft_lstclear(&a);
    ft_lstclear(&b);
    return (0);
}