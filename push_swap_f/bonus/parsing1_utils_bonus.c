/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/16 23:29:05 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>
int  check_min_max(long result, int sign)
{
    if(result > INT_MAX && result != 2147483648)
    {
        ft_putstr("Error\n");
        return(1);
    }
    if(result == 2147483648 && sign == 1)
    {
        ft_putstr("Error\n");
        return(1);
    }    
    return (0);
}
int spaces(char *s)
{
    int i = 0;
    int len_s = ft_strlen(s);
    while(s[i])
    {
        if(!(s[i] == ' '))
            return (0);
        i++;
    }
    if(i == len_s)
        return (1);
    return (0);   
}
int	ft_atoi(const char *str)
{
	int     i;
	int     sign;
	long    result;

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
    if(check_min_max(result, sign))
        return (1);
	return (sign * (int)result);
}


int case_one(char **res, char *av, int count_words, t_stack **stack)
{
    int i;
    int n;
    t_stack *new;
    i = -1;
    res = ft_split(av, ' ');
    char **p = res;//a->next
    res = NULL;
    system("leaks checker");
    if(!res)
        return (free_array(p), 1);
    while(++i < count_words)
    {

        if(spaces(res[i]) || check_char(res[i]))
            return (free_data(res, stack, new, 0), 1);
        n = ft_atoi(res[i]);
        new = ft_lstnew(n);
        if(!new)
            return (1);
        if(is_double(*stack, n))
            return (free_data(res, stack, new, 1), 1);
        ft_lstadd_back(stack, new);
    }
    free_array(res);

    return (0);
}

int case_two(char **res, char *av, t_stack **stack)
{
    int n;
    t_stack *new = NULL;
    res = ft_split(av, ' ');
    if(!res)
        return (1);
    if(spaces(av) || check_char(res[0]))
        return (free_data(res, stack, new, 1), 1);
    n = ft_atoi(res[0]);
    new = ft_lstnew(n);
    if(!new)
        return (1);
    if(is_double(*stack, n))
        return(free_data(res, stack, new, 1),1);
    ft_lstadd_back(stack, new);
    free_array(res);
    return (0);
}

int parsing(char *av, t_stack **stack, char c)
{
    char **res;
    int count_words;

    res = NULL;
    count_words = nbr_strings(av, c);
    if(count_words > 1)
    {
        if(case_one(res, av, count_words, stack))
            return (1); 
    }
    else
    {
        if(case_two(res, av, stack))
            return (1);     
    }

    return (0); 
}
