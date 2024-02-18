/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:39:43 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/18 15:51:49 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*new;

	if (!(*a))
		return ;
	new = ft_lstnew((*a)-> data);
	if (!new)
		return ;
	ft_lstadd_front(b, new);
	ft_lstdel_front(a);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new;

	if (!(*b))
		return ;
	new = ft_lstnew((*b)->data);
	if (!new)
		return ;
	ft_lstadd_front(a, new);
	ft_lstdel_front(b);
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
