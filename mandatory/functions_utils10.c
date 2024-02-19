/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:07 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 23:33:41 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack_a(t_stack *a)
{
	int	max;

	if (!(a))
		return (-1);
	max = a->data;
	while (a)
	{
		if (max < a->data)
			max = a->data;
		a = a -> next;
	}
	return (max);
}

t_best_move	set_best_move(t_stack *a, t_stack *b, int val_b)
{
	t_best_move	node;

	node.val_b = val_b;
	node.val_a = find_min_greater_than(a, node.val_b);
	node.cost_a = get_cost(a, node.val_a);
	node.cost_b = get_cost(b, node.val_b);
	if (node.cost_a == 0)
		node.move_a = 2;
	else
		node.move_a = get_move(a, node.val_a);
	if (node.cost_b == 0)
		node.move_b = 2;
	else
		node.move_b = get_move(b, node.val_b);
	node.operation = set_operation(node.move_a, node.move_b);
	node.cost_ab = set_cost_ab(node.move_a, node.move_b,
			node.cost_a, node.cost_b);
	return (node);
}

t_best_move	get_best_move(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	t_best_move	node;
	t_best_move	node1;

	tmp = b;
	node = set_best_move(a, b, tmp->data);
	while (tmp)
	{
		node1 = set_best_move(a, b, tmp->data);
		if (node.cost_ab > node1.cost_ab)
			node = node1;
		tmp = tmp->next;
	}
	return (node);
}

void	final_case(t_stack **a, t_stack **b)
{
	t_best_move	node;
	int			i;
	int			size;

	size = ft_lstsize(*b);
	i = -1;
	while (++i < size)
	{
		node = get_best_move(*a, *b);
		get_operation(a, b, node);
		pa(a, b);
	}
}

void	get_stack_a_sorted(t_stack **a, int size)
{
	int	min_a;
	int	index;

	if (!(*a))
		return ;
	min_a = min_stack_a(*a);
	index = get_index_of_node(*a, min_a);
	if (index == size - index)
	{
		while ((*a)-> data != min_a)
			ra(a, 1);
	}
	else if (index > size - index)
	{
		while ((*a)-> data != min_a)
			rra(a, 1);
	}
	else
	{
		while ((*a)-> data != min_a)
			ra(a, 1);
	}
}
