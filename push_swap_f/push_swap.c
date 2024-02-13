/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:01:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/13 18:33:36 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

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
// void f()
// {
//     system("leaks push_swap");
// }
int main(int ac, char *av[])
{
    t_stack *a;
    int i;
    
    i = 0;
    a = NULL;
    // atexit(f);
    if(ac == 1 || !strcmp(av[1], " "))
        return (0);
    while(++i < ac)
        parsing(av[i], &a, ' ');

    // display_a(a);

    ft_lstclear(&a);
    return (0);
}
