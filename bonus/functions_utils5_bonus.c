/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:39:43 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/22 13:21:37 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!(*a))
		return ;
	ptr = *a;
	*a = (*a)-> next;
	ptr -> next = *b;
	*b = ptr;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!(*b))
		return ;
	ptr = *b;
	*b = (*b)-> next;
	ptr -> next = *a;
	*a = ptr;
}

void	ra(t_stack **a)
{
	t_stack	*first_elem;
	t_stack	*last_elem;

	if (!(*a) || !(*a)-> next)
		return ;
	first_elem = *a;
	last_elem = ft_lstlast(*a);
	(*a) = (*a)-> next;
	last_elem->next = first_elem;
	first_elem->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*first_elem;
	t_stack	*last_elem;

	if (!(*b) || !(*b)-> next)
		return ;
	first_elem = *b;
	last_elem = ft_lstlast(*b);
	(*b) = (*b)-> next;
	last_elem->next = first_elem;
	first_elem->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
