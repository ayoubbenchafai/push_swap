/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/17 19:18:35 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <string.h>
#include <stdio.h>
void display_a(t_stack *a)
{
    printf("stack a:\n");
    while(a)
    {
        printf("%d ", a->data);
        a = a->next;
    }
        printf("\n");

}

int apply_instructions(t_stack **a,t_stack **b, char *s)
{ 
    if(!strcmp(s, "sa\n"))
        return (sa(a), 0);
    else if(!strcmp(s, "sb\n"))
        return (sb(b), 0);
    else if(!strcmp(s, "ss\n"))
        return (ss(a,b),0);
    else if(!strcmp(s, "pb\n"))
        return (pb(a,b), 0);
    else if(!strcmp(s, "pa\n"))
        return (pa(a,b), 0);
    else if(!strcmp(s, "ra\n"))
        return (ra(a), 0);
    else if(!strcmp(s, "rb\n"))
        return(rb(a), 0);
    else if(!strcmp(s, "rr\n"))
        return(rr(a,b), 0);
    else if(!strcmp(s, "rra\n"))
        return (rra(a), 0);
    else if(!strcmp(s, "rrb\n"))
        return (rrb(a), 0);
    else if(!strcmp(s, "rrr\n"))
        return (rrr(a,b), 0);
    else
        return (ft_putstr("Error\n") ,1);    
}

//ft_read
int	ft_check(char *s, char c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
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
int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    char *s;
    int i;
    i = 0;
    a = NULL;
    b = NULL;
    if(ac == 1)
        return (0); 
    while(++i < ac)
    {
        if(parsing(av[i], &a, ' '))
            return (1);
    }
    while (1)
    {
        s = get_next_line(0);
        if(!s)
        {
            if(is_sorted(a) && !b)
                return (ft_lstclear(&a),ft_putstr("OK\n"), 0);
            else
                return (ft_lstclear(&a),ft_lstclear(&b), ft_putstr("KO\n"), 1);
        }
        if(apply_instructions(&a, &b, s))
                return (free(s),ft_lstclear(&b), ft_lstclear(&a), 1);
        free(s);
    }
    return (0);
}
