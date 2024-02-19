/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:49 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
int  check_min_max(long result, int sign)
{
    if(result > INT_MAX && result != 2147483648)
    {
        write(2, "Error\n", 6);
        return(1);
    }
    if(result == 2147483648 && sign == 1)
    {
        write(2, "Error\n", 6);
        return(1);
    }    
    return (0);
}
int add_to_stack(t_stack **stack, char *res)
{
    int n;
    t_stack *new;
    t_stack *p_new;
    
    new = NULL;
    if(check_char(res))
        return (write(2, "Error\n", 6), 1);
    n = ft_atoi(res);
    new = ft_lstnew(n);
    p_new = new;
    if(!new)
        return (free(p_new), 1);
    if(is_double(*stack, n))
        return (free(new), write(2, "Error\n", 6), 1);
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
    if(check_char(res[0]))
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
