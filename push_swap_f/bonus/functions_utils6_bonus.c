/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils6_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:44:57 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/18 16:10:22 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!(*a) || !(*a)-> next)
		return ;
	last = ft_lstlast(*a);
	before_last = ft_lst_before_last(*a);
	last->next = *a;
	*a = last;
	before_last -> next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!(*b) || !(*b)-> next)
		return ;
	last = ft_lstlast(*b);
	before_last = ft_lst_before_last(*b);
	last->next = *b;
	*b = last;
	before_last -> next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
