/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:23:50 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/13 16:25:02 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
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
