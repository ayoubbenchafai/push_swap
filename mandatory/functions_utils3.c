/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:52 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 22:59:16 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_stack_a(t_stack *a)
{
	int	min;

	if (!(a))
		return (-1);
	min = a->data;
	while (a)
	{
		if (min > a -> data)
			min = a -> data;
		a = a -> next;
	}
	return (min);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	free_array(char **av)
{
	int	i;

	i = 0;
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
	exit(1);
}
