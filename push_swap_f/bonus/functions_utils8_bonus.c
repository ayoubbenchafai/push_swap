/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils8_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:24:10 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/15 18:48:21 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int  set_operation(int move_a, int move_b)
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
void operation2_rr(t_stack **a, t_stack **b, int i_a, int  i_b)
{
    int c;
    
    if(i_a == i_b)
    {
        while(i_a--)
        rr(a,b);
    }
    else if(i_a > i_b)
    {
        c = i_a - i_b;
        while(i_b--)
            rr(a, b);
        while(c--)
            ra(a);
    }
    else if(i_a < i_b)
    {
        c = i_b -i_a;
        while(i_a--)
            rr(a, b);
        while(c--)
            rb(b);
    }
}
void operation2_rrr(t_stack **a, t_stack **b, int i_a, int  i_b)
{
    int c;
    
    if(i_a == i_b)
    {
        while(i_a--)
            rrr(a,b);
        }
    else if(i_a > i_b)
    {
        c = i_a - i_b;
        while(i_b--)
            rrr(a, b);
        while(c--)
            rra(a);
    }
    else if(i_a < i_b)
    {
        c = i_b -i_a;
        while(i_a--)
            rrr(a, b);
        while(c--)
            rrb(b);
    }
}
void operation2(t_stack **a, t_stack **b, t_best_move node)
{
    if(node.operation == 1)
        operation2_rr(a, b, node.cost_a, node.cost_b);
    else if(node.operation == 2)
        operation2_rrr(a, b, node.cost_a, node.cost_b);
    else 
        return ;
}