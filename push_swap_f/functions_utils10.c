/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:07 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/14 16:50:31 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_best_move     set_best_move(t_stack *a, t_stack *b, int val_b)
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

t_best_move     get_best_move(t_stack *a, t_stack *b)
{
    t_stack *tmp;
    
    tmp = b;
    t_best_move node = set_best_move(a, b, tmp->data);
    while(tmp)
    {
        t_best_move node1 = set_best_move(a, b, tmp->data);
        if(node.cost_ab > node1.cost_ab)
            node =node1;
        tmp = tmp->next;
    }
    return node;
}
void            final_case(t_stack **a, t_stack **b)
{
    t_best_move node;
    int i ;
    int size; 
    size = ft_lstsize(*b);
    i= -1;
    while(++i < size)
    {
        node =get_best_move(*a, *b);
        get_operation(a, b, node);
        pa(a, b);
    }
}