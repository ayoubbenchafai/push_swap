/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:55:02 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 23:37:51 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	if (!a || !(a -> next))
		return (1);
	while (a -> next)
	{
		if ((a -> data) > (a -> next -> data))
			return (0);
		a = a -> next;
	}
	return (1);
}

static void	sort_data(t_stack **a, t_stack **b, int size, int median)
{
	int	i;

	if (!(*a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		i = -1;
		while (++i < size - 3)
		{
			pb(a, b);
			if (ft_lstsize(*b) >= 2)
			{
				if ((*b)->data < median)
					rb(b, 1);
			}
		}
		sort_three(a);
		final_case(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		size;
	int		median;

	i = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (++i < ac)
		parsing(av[i], &a, ' ');
	if (is_sorted(a))
		return (0);
	size = ft_lstsize(a);
	median = get_median(a);
	sort_data(&a, &b, size, median);
	get_stack_a_sorted(&a, size);
	ft_lstclear(&a);
	return (0);
}
