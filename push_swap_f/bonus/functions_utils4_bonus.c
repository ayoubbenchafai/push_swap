/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils4_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:34:08 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/15 18:45:07 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int is_double(t_stack *stack, int number)
{
    while(stack)
    {
        if(stack->data == number)
            return (1);
        stack = stack->next;
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
