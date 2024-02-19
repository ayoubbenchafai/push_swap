/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils6_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:20:54 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 17:36:34 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	find_min_greater_than(t_stack *a, int val)
{
	int		res;
	t_stack	*r;
	t_stack	*tmp;

	r = a;
	tmp = get_greater_values(a, val);
	if (tmp == NULL)
		res = min_stack_a(r);
	else
		res = min_stack_a(tmp);
	ft_lstclear(&tmp);
	return (res);
}

t_stack	*get_greater_values(t_stack *a, int val)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = NULL;
	while (a)
	{
		if (a -> data > val)
		{
			new = ft_lstnew(a -> data);
			if (!new)
			{
				ft_lstclear(&tmp);
				ft_lstclear(&a);
				exit(1);
			}
			ft_lstadd_front(&tmp, new);
		}
		a = a -> next;
	}
	return (tmp);
}

int	get_index_of_node(t_stack *s, int val)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s)
	{
		if (s -> data == val)
			return (i);
		i++;
		s = s ->next;
	}
	return (-1);
}

int	get_move(t_stack *s, int val)
{
	int	size;
	int	index;

	if (!s)
		return (-1);
	size = ft_lstsize(s);
	index = get_index_of_node(s, val);
	if (index > size - index)
		return (1);
	return (0);
}

int	get_cost(t_stack *s, int val)
{
	int	size;
	int	index;

	if (!s)
		return (-1);
	size = ft_lstsize(s);
	index = get_index_of_node(s, val);
	if (index > size - index)
		return (size - index);
	return (index);
}
