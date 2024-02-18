/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:52 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/18 15:56:23 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_putstr(char *s, int i)
{
	while (*s != '\0')
		write(i, s++, 1);
}

int	spaces(char *s)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (s[i])
	{
		if (!(s[i] == ' '))
			return (0);
		i++;
	}
	if (i == len_s)
		return (1);
	return (0);
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
	ft_putstr("Error\n", 2);
	free_array(res);
	ft_lstclear(stack);
	if (vlag == 1)
		free(new);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (check_min_max(result, sign))
		exit (1);
	return (sign * (int)result);
}
