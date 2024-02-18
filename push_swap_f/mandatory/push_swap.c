/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/15 18:05:16 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <signal.h>


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
void f(void)
{
            system("leaks push_swap");

}
int is_sorted(t_stack *a)
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

//26 lines
static void sort_data(t_stack **a, t_stack **b, int size, int  median)
{
    int i;
    
    if(!(*a))
        return ;
    if(size == 2)
        sort_two(a);
    else if(size == 3)
        sort_three(a);
    else
    {
        i = -1;
        while(++i < size - 3)
        {
            pb(a, b);
            if(ft_lstsize(*b) >= 2)
            {
                    if((*b)->data < median)
                        rb(b, 1);
            } 
        }
        sort_three(a);
        final_case(a, b);
    }
}
void sig_handle(int sig)
{
    (void)sig;
}

int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    int i;
    int size;
    int median;
    
    // signal(SIGUSR1, sig_handle);
    // printf("PID : %d\n", getpid());
    // atexit(f);
    i = 0;
    a = NULL;
    b = NULL;
    if(ac == 1)
        return (0);
    while(++i < ac)
        parsing(av[i], &a, ' ');
    if(is_sorted(a))
        return (0);
    size = ft_lstsize(a);
    median = get_median(a);
    sort_data(&a, &b, size, median);
    get_stack_a_sorted(&a, size);
    display_a(a);
    ft_lstclear(&a);
    // ft_lstclear(&b);
    
    return (0);
}
