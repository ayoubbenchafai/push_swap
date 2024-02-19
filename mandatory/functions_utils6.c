/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:44:57 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 23:11:57 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int vlag)
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
	if (vlag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int vlag)
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
	if (vlag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	bubble_sort(int *t, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (t[i] > t[j])
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median(t_stack *stack)
{
	int	*t;
	int	i;
	int	size;
	int	median;
	int	index_median;

	size = ft_lstsize(stack);
	t = malloc(sizeof(int) * size);
	if (!t || !stack)
		return (-1);
	i = -1;
	while (++i < size)
	{
		t[i] = stack->data;
		stack = stack->next;
	}
	bubble_sort(t, size);
	index_median = (size / 2);
	median = t[index_median];
	free(t);
	return (median);
}
