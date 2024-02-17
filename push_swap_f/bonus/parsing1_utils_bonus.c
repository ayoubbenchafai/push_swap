/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/17 19:13:01 by aben-cha         ###   ########.fr       */
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
int add_to_stack(t_stack **stack, char *res)
{
    int n;
    t_stack *new;
    t_stack *p_new;
    
    new = NULL;
    if(check_char(res))
        return (ft_putstr("Error\n"), 1);
    n = ft_atoi(res);
    new = ft_lstnew(n);
    p_new = new;
    if(!new)
        return (free(p_new), 1);
    if(is_double(*stack, n))
        return (free(new), ft_putstr("Error\n"), 1);
    ft_lstadd_back(stack, new);
    return (0);
}

int case_one(char **res, char *av, int count_words, t_stack **stack)
{
    int i;
    char **p;
    
    i = -1;
    res = ft_split(av, ' ');
    p = res;
    if(!res)
        return (free_array(p), 1);
    while(++i < count_words)
    {
        if(add_to_stack(stack, res[i]))
            return (1);
    }
    return (free_array(res), 0);
}
int case_two(char **res, char *av, t_stack **stack)
{
    int n;
    char **p;
    t_stack *new; 
    t_stack *p_new; 
    
    new= NULL;
    res = ft_split(av, ' ');
    p = res;
    if(!res)
        return (free_array(p), 1);
    if(spaces(av) || check_char(res[0]))
        return (free_data(res, stack, new, 0), 1);
    n = ft_atoi(res[0]);
    new = ft_lstnew(n);
    p_new = new;
    if(!new)
        return (free(p_new), 1);
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
