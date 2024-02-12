/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:25:19 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/12 16:02:28 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>


int check_char(char *s)
{
    while(*s)
    {
        if(*s == '-' || *s == '+')
            s++;
        if(!(*s >= '0' && *s <= '9'))
            return (1);
        s++;
    }  
    return (0);

}
void free_array(char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}
void f()
{
    system("leaks a.out");
}
int is_double(t_stack *stack, int number)
{
    int i = 0;
    while(stack)
    {
        if(stack->data == number)
            return (1);
        stack = stack->next;
    }
    return (0);
}
static int ft_parsing(char *av, char c, t_stack **stack)
{
    int len_string;
    int n;
    char **res = NULL;
    t_stack *new;
    len_string = nbr_strings(av, c);
    if (len_string > 1)
    {
        res = ft_split(av, c);
        int i = -1;
        while(++i < len_string)
        {
            if(check_char(res[i]))
                return (ft_putstr("Error\n"), free_array(res), ft_lstclear(stack),free(new), 1);
            n = ft_atoi(res[i]);
            new = ft_lstnew(n);
            if(!new)
                return (1);
            if(is_double(*stack, n))
                return (ft_putstr("Error\n"), free_array(res), ft_lstclear(stack),free(new), 1); 
            ft_lstadd_back(stack, new);
        }
        free_array(res);
    }
    else
    {
        res = ft_split(av, c);
        if(check_char(res[0]))
            return (ft_putstr("Error\n"), free_array(res), ft_lstclear(stack), 1);
        n = ft_atoi(res[0]);
        new = ft_lstnew(n);
        if(!new)
                return (1);
        if(is_double(*stack, n))
            return (ft_putstr("Error\n"), free_array(res), ft_lstclear(stack), free(new), 1);
        ft_lstadd_back(stack, new);
        free_array(res);
    }
    return (0);
}



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
int main(int ac, char *av[])
{
    atexit(f);
    t_stack *a;
    int i;
    
    i = 0;
    a = NULL;
    while(++i < ac)
    {
        if(ft_parsing(av[i], ' ', &a))
            return (1);        
    }
    display_a(a);
    ft_lstclear(&a);
    return (0);
}
