/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:39:43 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 23:06:43 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}

void	ra(t_stack **a, int vlag)
{
	t_stack	*first_elem;
	t_stack	*last_elem;

	if (!(*a))
		return ;
	first_elem = *a;
	last_elem = ft_lstlast(*a);
	(*a) = (*a)-> next;
	last_elem->next = first_elem;
	first_elem->next = NULL;
	if (vlag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int vlag)
{
	t_stack	*first_elem;
	t_stack	*last_elem;

	if (!(*b))
		return ;
	first_elem = *b;
	last_elem = ft_lstlast(*b);
	(*b) = (*b)-> next;
	last_elem->next = first_elem;
	first_elem->next = NULL;
	if (vlag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
