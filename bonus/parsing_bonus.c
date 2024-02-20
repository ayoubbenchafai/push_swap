/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/20 22:52:26 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_min_max(long result, int sign)
{
	if (result > INT_MAX && result != 2147483648)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (result == 2147483648 && sign == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	parsing(char *av, t_stack **stack, char c)
{
	int		i;
	int		n;
	char	**res;
	t_stack	*new;

	i = -1;
	res = ft_split(av, c);
	if (!res || !res[0])
		return (write(2, "Error\n", 6), ft_lstclear(stack), 1);
	while (res[++i])
	{
		if (check_char(res[i]))
			return (free_data(res, stack, new, 0), 1);
		n = ft_atoi(res[i]);
		new = ft_lstnew(n);
		if (!new)
			return (free_data(res, stack, new, 0), 1);
		if (is_double(*stack, n))
			return (free_data(res, stack, new, 1), 1);
		ft_lstadd_back(stack, new);
	}
	free_array(res);
	return (0);
}
