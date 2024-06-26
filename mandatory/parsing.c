/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/22 15:34:18 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_max(long result, int sign)
{
	if (result > INT_MAX && result != 2147483648)
		return (1);
	if (result == 2147483648 && sign == 1)
		return (1);
	return (0);
}

int	check_errors(char **res, t_stack **stack, t_stack *new, int i)
{
	long	n;

	if (check_char(res[i]))
		return (free_data(res, stack, new, 0), 1);
	n = ft_atoi(res[i]);
	if (n == 2147483648)
		return (free_data(res, stack, new, 0), 1);
	new = ft_lstnew(n);
	if (!new)
		return (free_data(res, stack, new, 0), 1);
	if (is_double(*stack, n))
		return (free_data(res, stack, new, 1), 1);
	ft_lstadd_back(stack, new);
	return (0);
}

int	parsing(char *av, t_stack **stack, char c)
{
	int		i;
	char	**res;
	t_stack	*new;

	i = -1;
	new = NULL;
	res = ft_split(av, c);
	if (!res || !res[0])
		return (free_data(res, stack, new, 0), 1);
	while (res[++i])
	{
		if (check_errors(res, stack, new, i))
			return (1);
	}
	free_array(res);
	return (0);
}

int	is_sorted(t_stack *a)
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

void	sort_data(t_stack **a, t_stack **b, int size, int median)
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
