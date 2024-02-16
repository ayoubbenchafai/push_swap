/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils6_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:44:57 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/16 23:32:12 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void rra(t_stack **a)
{
    t_stack *last;
    t_stack *before_last;
    
    if(!(*a) || !(*a)->next)
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
    
    if(!(*b) || !(*b)->next)
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
    int *t;
    int i ;
    int size;
    int median;
    int index_median; 
    
    size = ft_lstsize(stack);
    t = malloc(sizeof(int) * size);
    if(!t || !stack)
       return (-1);
    i = -1;
    while(++i < size)
    {
        t[i] = stack->data;
        stack = stack->next;
    }
    bubble_sort(t, size);
    index_median = (size / 2);
    median = t[index_median];
    free(t);
    return (median);        
}
