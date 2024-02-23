/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:52 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/23 22:28:45 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_array(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_data(char **res, t_stack **stack, t_stack *new, int vlag)
{
	write(2, "Error\n", 6);
	free_array(res);
	ft_lstclear(stack);
	if (vlag == 1)
		free(new);
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!(*a) || !(*a)-> next)
		return ;
	last = ft_lstlast(*a);
	before_last = ft_lst_before_last(*a);
	last->next = *a;
	*a = last;
	before_last -> next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!(*b) || !(*b)-> next)
		return ;
	last = ft_lstlast(*b);
	before_last = ft_lst_before_last(*b);
	last->next = *b;
	*b = last;
	before_last -> next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
