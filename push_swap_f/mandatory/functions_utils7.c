/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:20:54 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 00:53:31 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_stack_a(t_stack *a)
{
    int min;
    
    if(!(a))
        return (-1);
    min = a->data;
    while(a)
    {
        if(min > a->data)
            min = a->data;
        a = a -> next;
    }
    return (min);
}
void free_new(t_stack *new, int data)
{
    t_stack * p_new;
    new = ft_lstnew(data);
    p_new = new;
    if(!new)
    {
        free(p_new);
        exit(1);
    }
}
int get_max(t_stack *a, int val)
{
    int res;
    t_stack *r;
    t_stack *tmp;
    t_stack *new;
    
    r = a;
    tmp = NULL;
    while(a)
    {
        if(a->data > val)
        {
            new = ft_lstnew(a->data);
            if(!new)
            {
                ft_lstclear(&tmp);
                ft_lstclear(&a);
                exit(1);
            }
            ft_lstadd_front(&tmp, new);
        }
        a = a -> next;
    }
    if (tmp == NULL)
        res = min_stack_a(r);
    else
        res = min_stack_a(tmp);
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
        s = s ->next;
    }
    return (-1);
}
int get_move(t_stack *s, int val)
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
        return (size - index);
    return (index);
}