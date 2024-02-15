/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:39:43 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/15 18:47:05 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void ra(t_stack **a, int vlag)
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
    if (vlag == 1)
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