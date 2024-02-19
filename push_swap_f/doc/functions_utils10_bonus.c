/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils10_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:29:24 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/19 17:39:23 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
int min_stack_a(t_stack *a)
{
    int min;
    
    if(!(a))
        return (-1);
    min = a->data;
    while(a)
    {
        if(min > a->data)
            min = a->data;
        a = a -> next;
    }
    return (min);
}
int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
int apply_instructions(t_stack **a,t_stack **b, char *s)
{ 
    if(!ft_strcmp(s, "sa\n"))
        return (sa(a), 0);    
    else if(!ft_strcmp(s, "sb\n"))
        return (sb(b), 0); 
    else if(!ft_strcmp(s, "ss\n"))
        return (ss(a,b), 0); 
    else if(!ft_strcmp(s, "pb\n"))
        return (pb(a,b), 0);
    else if(!ft_strcmp(s, "pa\n"))
        return (pa(a,b), 0);  
    else if(!ft_strcmp(s, "ra\n"))
        return (ra(a), 0);  
    else if(!ft_strcmp(s, "rb\n"))
        return(rb(b), 0);   
    else if(!ft_strcmp(s, "rr\n"))
        return(rr(a,b), 0);  
    else if(!ft_strcmp(s, "rra\n"))
        return (rra(a), 0);   
    else if(!ft_strcmp(s, "rrb\n"))
        return (rrb(b), 0);  
    else if(!ft_strcmp(s, "rrr\n"))
        return (rrr(a,b), 0);
    else
        return (write(2, "Error\n", 6) ,1);    
}
int is_sorted(t_stack *a)
{
    if(!a || !a->next)
        return (1);
    while(a->next)
    {
        if((a->data) > (a->next->data))
            return (0);
        a = a->next;
    }
    return 1;
}
int read_instructions(t_stack *a, t_stack *b)
{
    char *s;
    char *p;
    while (1)
    {
        s = get_next_line(0);
        p = s;
        if(!s)
        {  
            if(is_sorted(a) && !b)
                return (ft_lstclear(&a),write(1, "OK\n", 3), 0);
            else
                return (ft_lstclear(&a),ft_lstclear(&b), write(1, "KO\n", 3), 1);
        }
        if(apply_instructions(&a, &b, s))
                return (free(s),ft_lstclear(&b), ft_lstclear(&a), 1);
        free(s);
    }
    return (0);
}
