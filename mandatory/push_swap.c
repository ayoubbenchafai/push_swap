/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:55:02 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/21 23:23:49 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (parsing(av[i], &a, ' '))
			return (1);
	}
	if (is_sorted(a))
		return (ft_lstclear(&a), 0);
	size = ft_lstsize(a);
	median = get_median(a);
	sort_data(&a, &b, size, median);
	get_stack_a_sorted(&a, size);
	return (0);
}
