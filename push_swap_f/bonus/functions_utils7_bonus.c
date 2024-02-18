/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils7_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:20:54 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/18 22:43:14 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
int get_max(t_stack *a, int val)
{
    int res;
    t_stack *r;
    t_stack *tmp;
    
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