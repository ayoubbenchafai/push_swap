/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:49:47 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/02 21:43:52 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int data;
	struct s_stack	*next;
}		t_stack;

t_stack *ft_lstnew(int data);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_putstr(char *s);
int	    nbr_strings(const char *s, char c);
char	**ft_split(char const *s, char c);
int     ft_atoi(const char *str);


#endif