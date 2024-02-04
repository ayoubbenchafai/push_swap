/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:45:32 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/04 19:53:10 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int data;
    int index;
	struct s_stack	*next;
}		t_stack;
t_stack	*ft_lstnew(int data, int index)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(!new)
        return (NULL);
    new->data = data;
    new->index = index;
    new->next = NULL;
    return (new);
}
t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	if (!ptr)
	{
		*lst = new;
		return ;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
	}
}
void display_a(t_stack *a)
{
    printf("stack a:\n");

    while(a )
    {
        printf("node : %d\n", a->data);
        a = a->next;
    }
}


int main() {
    t_stack *a = NULL;
    int i = 0;
    int t[6] = {2,1,3,6,5,8};
    t_stack *new;
    while(i < 6)
    {
        new = ft_lstnew(t[i], i);
        ft_lstadd_back(&a, new);
        i++;
    }
    
    printf("index  of %d : %d\n", 5, get_index_of_node(a, 5));

    return 0;
}