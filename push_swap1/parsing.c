/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:25:19 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/12 23:50:50 by aben-cha         ###   ########.fr       */
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
int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		// if ((result >= 9223372036854775807) && (sign == 1))
		// 	return (-1);
		// if ((result > 9223372036854775807) && (sign == -1))
		// 	return (0);
		i++;
	}
        // printf("result      : %lu\n",result);
        // printf("result sign : %d\n",(sign) * (int)result);

    if(result > INT_MAX && result != 2147483648)
    {
        puts("Error\n");
        exit(1);
    }
	return (sign * (int)result);
}
int check_min_max(int n)
{
    if(n > INT_MAX || n < INT_MIN)
        return(0);
    return (1);
}
int main(int ac, char *av[])
{
    // printf("%d\n",ft_atoi("2147483649"));
    // printf("%d\n",ft_atoi("2147483648"));
    // printf("%d\n",ft_atoi("-2147483648"));
    printf("%d\n",ft_atoi("2147483647"));
    return (0);
}
