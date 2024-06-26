/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:34:08 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 23:01:24 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->data == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack **a, int vlag)
{
	if (!(*a) || !(*a)-> next)
		return ;
	swap(&(*a)-> data, &(*a)-> next -> data);
	if (vlag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int vlag)
{
	if (!(*b) || !(*b)-> next)
		return ;
	swap(&(*b)-> data, &(*b)-> next -> data);
	if (vlag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 1);
	sa(b, 1);
	write(1, "ss\n", 3);
}
