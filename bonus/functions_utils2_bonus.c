/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:23:50 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/23 22:31:00 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*ptr1;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr1 = ptr -> next;
		free(ptr);
		ptr = ptr1;
	}
	*lst = NULL;
}

t_stack	*ft_lst_before_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstdel_front(t_stack **lst)
{
	t_stack	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	*lst = (*lst)-> next;
	free(ptr);
}

int	check_char(char *s)
{
	if (!s)
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	if (!(*s >= '0' && *s <= '9'))
		return (1);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
		s++;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	r;

	r = 2147483648;
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && result <= 2147483648)
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (check_min_max(result, sign))
		return (r);
	return ((long)sign * result);
}
