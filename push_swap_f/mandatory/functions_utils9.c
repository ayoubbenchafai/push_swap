/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:45:29 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 20:19:02 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	 sort_two(t_stack **a)
{
	if (!(*a))
		return ;
	if (((*a)-> data) > ((*a)-> next-> data))
		sa(a, 1);
	else
		return ;
}

void	sort_three(t_stack **a)
{
	int max;
    
    if(!(*a))
        return ;
    max = max_stack_a(*a);
    if((*a)->data == max)
    {
        ra(a, 1);
        sort_two(a);
    }
    else if((*a)->next->data == max)
    {
        rra(a, 1);
        sort_two(a);
    }
    else    
        sort_two(a);
}
void opeartion1_a(t_stack **a, t_best_move node)
{
    if(!(*a))
        return ;
    int size = ft_lstsize(*a);
    int index = get_index_of_node(*a, node.val_a);

    if(node.move_a == 0)
    {
        while(index--)
            ra(a, 1);
    }
    else if(node.move_a == 1)
    {
        size = size - index;
        while(size--)
            rra(a, 1);
    }
    else
        return ;
}
void opeartion1_b(t_stack **b, t_best_move node)
{
    if(!(*b))
        return ;
    int size = ft_lstsize(*b);
    int index = get_index_of_node(*b, node.val_b);

    if(node.move_b == 0)
    {
        while(index--)
            rb(b, 1);
    }
    else if(node.move_b == 1)
    {
        size = size - index;
        while(size--)
            rrb(b, 1);
    }
    else
        return ;
}
int set_cost_ab(int move_a, int move_b, int cost_a, int cost_b)
{
    if(move_a == move_b)
    {
        if(cost_a  > cost_b)
            return (cost_a + 1);
        else    
            return (cost_b + 1);
    }
    else
        return (cost_a + cost_b + 1);
}