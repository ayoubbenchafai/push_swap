/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:25:19 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/13 13:07:30 by aben-cha         ###   ########.fr       */
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



// void display_a(t_stack *a)
// {
//     printf("stack a:\n");

//     while(a)
//     {
//         printf("%d ", a->data);
//         a = a->next;
//     }
//         printf("\n");
// }
//-----------------------
// atexit(f);
//     t_stack *a;
//     int i;
    
//     i = 0;
//     a = NULL;
//     while(++i < ac)
//     {
//         if(ft_parsing(av[i], ' ', &a))
//             return (1);        
//     }
//     display_a(a);
//     ft_lstclear(&a);
//-----------------------
// INT_MAX : 2147483647
// INT_MIN : -2147483648
int  check_min_max(long result, int sign)
{
    if(result > INT_MAX && result != 2147483648)
    {
        puts("Error\n");
        return(1);
    }
    if(result == 2147483648 && sign == 1)
    {
        puts("Error\n");
        return(1);
    }    
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
        exit (-1);
	return (sign * (int)result);
}

int main(int ac, char *av[])
{
    char *res[10] = {"1199576152", "1984514596", "2076464756", "-56348301", "-2147483648" ,"-829173723", "-2147483649" ,"1558407338" ,"-496481897","-1578373440"};
    // printf("%d\n",ft_atoi("-2147483649"));
    // printf("case 1 : %d\n",ft_atoi("-2147483648"));
    int i = -1;
    while(++i < 10)
        printf("res %d, %d\n", i, ft_atoi(res[i]));
    return (0);
}
