/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/15 22:59:06 by aben-cha         ###   ########.fr       */
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

void instructions(t_stack **a,t_stack **b, char *s)
{
    if(!s || !(*a))
        return ;
        
    if(!strcmp(s, "sa\n"))
        sa(a);
    else if(!strcmp(s, "sb\n"))
        sb(b);
    else if(!strcmp(s, "ss\n"))
        ss(a,b);
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

static int is_sorted(t_stack *a)
{
    if(!a)
        return (1);
    while(a->next)
    {
        if(a->data > a->next->data)
            return (0);
        a = a->next;
    }
    return 1;
}
void display_b(t_stack *b)
{
    printf("stack b:\n");

    while(b)
    {
        printf("%d ", b->data);
        b = b->next;
    }
        printf("\n");
}

// static void sort_data(t_stack **a, t_stack **b, int size, int  median)
// {
//     int i;
    
//     if(!(*a))
//         return ;
//     if(size == 2)
//         sort_two(a);
//     else if(size == 3)
//         sort_three(a);
//     else
//     {
//         i = -1;
//         while(++i < size - 3)
//         {
//             pb(a, b);
//             if(ft_lstsize(*b) >= 2)
//             {
//                     if((*b)->data < median)
//                         rb(b);
//             } 
//         }
//         sort_three(a);
//         final_case(a, b);
//     }
// }

// rra
// pb
// sa
// rra
// pa
int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    int i;
    // int size;
    // int median;
    
    i = 0;
    a = NULL;
    b = NULL;
    if(ac == 1)
        return (0); while(++i < ac)
        parsing(av[i], &a, ' ');
    
    i = -1;
    while(1)
    {
        char *s = get_next_line(0);
        if(!s)
            return (free(s), 1);
        instructions(&a, &b, s);
        if(s == NULL)
            return 1;
        free(s);
    }
    if(is_sorted(a))
        return (ft_putstr("OK\n"),0);
    // display_a(a);
    // if(is_sorted(a))
    //     return (ft_putstr("OK\n"),0);
    // else
    //     return (ft_putstr("KO\n"),0); 
    ft_lstclear(&a);

    return (0);
}
