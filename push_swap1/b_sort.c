/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:05:29 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/11 20:23:22 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>
void bubble_sort(int *t, int n) 
{
    int i = 0;
    int j;
    int tmp;
    while (i < n)
    {
        j = i +1;
        while(j < n)
        {
            if (t[i] > t[j])
            {
                tmp = t[i];  
                t[i] = t[j];  
                t[j] = tmp;
            }
            j++;
        }
        i++;
    }
} 

// void get_median(int ac, char *av[])
// {
//     int i;
//     i = 1;
//     int j = 0;
//     int t[ac - 1];
//     while(i < ac)
//         t[j++] = atoi(av[i++]);
//     bubble_sort(t, ac - 1);
//     int median = 0;
//     int index_median = (ac - 1) / 2;
//     median = t[index_median];
//     printf("index_median     =      %d\n",index_median);
//     printf("value the median =  %d\n",median);
//     // return (t);   
// }

// int get_median(t_stack *stack)
// {
//     int size = ft_lstsize(stack);
//     int *t = malloc(sizeof(int));
//     if(!t)
//        return (-1);

//     int i = -1;
//     while(++i < size)
//     {
//         t[i] = stack->data;
//         stack = stack->next;
//     }

//     bubble_sort(t, size);
//     int median = -1;
//     int index_median = (size / 2);
//     median = t[index_median];

//     return (median);
            
// }
int main(int ac, char *av[])
{   
    return (0);
}