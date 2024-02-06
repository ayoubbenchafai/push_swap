/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:53:50 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/05 23:43:18 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	*lst = new;
}

int		ft_lstsize(t_stack *lst)
{
	int		len;
	t_stack	*ptr;

	if (!lst)
		return (0);
	len = 0;
	ptr = lst;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
    }
	return (len);
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

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

t_stack *ft_lst_before_last(t_stack *lst)
{
    if(!lst)
        return (NULL);
    while(lst->next->next)
        lst = lst->next;
    return (lst);
}

void ft_lstdel_front(t_stack **lst)
{
    if(!lst)
        return ;
    t_stack *ptr;

    ptr = *lst;
    *lst = (*lst) -> next;
    free(ptr);
}
void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*ptr1;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr1 = ptr -> next;
		ft_lstdelone(ptr);
		ptr = ptr1;
	}
	*lst = NULL;
}

void	ft_putstr(char *s)
{
    while (*s != '\0')
        write(1, s++, 1);
}


