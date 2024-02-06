/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:45:32 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/05 23:42:38 by aben-cha         ###   ########.fr       */
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
t_stack	*ft_lstnew(int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(!new)
        return (NULL);
    new->data = data;
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

    while(a)
    {
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}

void ra(t_stack **a)
{
    t_stack *first_elem;
    t_stack *last_elem;
    
    if(!(*a))
        return ;
    first_elem = *a;
    last_elem = ft_lstlast(*a);
    (*a) = (*a)->next;
    last_elem->next = first_elem;
    first_elem->next = NULL; 
}
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	*lst = new;
}


void rra(t_stack **a)
{
    t_stack *last;
    t_stack *before_last;
    
    if(!(*a))
        return ;
    last = ft_lstlast(*a);
    before_last = ft_lst_before_last(*a);
    last->next = *a;
    *a = last;
    before_last->next = NULL;
}

int main() {
    t_stack *a = NULL;
    int i = 0;
    int t[6] = {1, 2, 9, 6, 5, 8};
    t_stack *new;
    while(i < 6)
    {
        new = ft_lstnew(t[i]);
        ft_lstadd_back(&a, new);
        i++;
    }
    display_a(a);
    ra(&a);
    display_a(a);

    return 0;
}