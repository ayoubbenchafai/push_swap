/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/16 23:29:27 by aben-cha         ###   ########.fr       */
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

int instructions(t_stack **a,t_stack **b, char *s)
{
    if(!s || !(*a))
        return 1;  
    if(!strcmp(s, "sa\n"))
        sa(a);
    else if(!strcmp(s, "sb\n"))
        sb(b);
    else if(!strcmp(s, "ss\n"))
    {
        ss(a,b);
        display_a(*a);
        display_a(*b);
    }
    else if(!strcmp(s, "pb\n"))
        pb(a,b);
    else if(!strcmp(s, "pa\n"))
        pa(a,b);
    else if(!strcmp(s, "ra\n"))
        ra(a);
    else if(!strcmp(s, "rb\n"))
        rb(a);
    else if(!strcmp(s, "rr\n"))
        rr(a,b);
    else if(!strcmp(s, "rra\n"))
        rra(a);
    else if(!strcmp(s, "rrb\n"))
        rrb(a);
    else if(!strcmp(s, "rrr\n"))
        rrr(a,b);
    else
        return (ft_putstr("Error\n") ,1);     
    
    return (0);
}
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

void f()
{
    system("leaks checker");
}
int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    char *s;
    int i;
    // atexit(f);
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
                return ( ft_lstclear(&a),ft_putstr("OK\n"), 0);
            else
                return (ft_lstclear(&a),ft_lstclear(&b), ft_putstr("KO\n"), 0);
        }
        if(instructions(&a, &b, s))
                return (free(s),ft_lstclear(&b), ft_lstclear(&a), 1);
        free(s);
    }
    return (0);
}
